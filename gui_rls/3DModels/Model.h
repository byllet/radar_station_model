#ifndef MODEL_H
#define MODEL_H

#include <iostream>
#include <vector>

#include <GLUT/glut.h>
#include <gl.h>
#include <glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

class Model3D {
public:
    Model3D(const std::string& filePath, float scale) {
        loadModel(filePath, scale);
    }

    void draw(const glm::vec3& position, const glm::vec3& viewDir) {
        glPushMatrix();

        glm::vec3 originalYAxis(0.0f, 1.0f, 0.0f);
        glm::vec3 targetDirection = glm::normalize(viewDir);
        float angle = acos(glm::dot(originalYAxis, targetDirection));
        glm::vec3 rotationAxis = glm::cross(originalYAxis, targetDirection);
        glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f), angle, rotationAxis);
        for (auto& mesh : meshes) {
            mesh.draw(position, rotationMatrix);
        }

        glPopMatrix();
    }

private:

    class Mesh {
    public:
        void draw(const glm::vec3 position, const glm::mat4& rotationMatrix) const{
            glColor3f(0.5, 0.5, 0.5);
            glBegin(GL_TRIANGLES);
            for (const auto& vertex : vertices) {
                glm::vec4 rotatedCoordinates = rotationMatrix * glm::vec4(vertex.x, vertex.y, vertex.z, 1.0f);
                glVertex3f(rotatedCoordinates.x + position.x, rotatedCoordinates.y + position.y, rotatedCoordinates.z + position.z);
            }
            glEnd();
        }

        std::vector<glm::vec3> vertices;
    };

    void loadModel(const std::string& filePath, float scale) {
        Assimp::Importer importer;
        const aiScene* scene = importer.ReadFile(filePath,
                                                 aiProcess_Triangulate | aiProcess_FlipUVs | aiProcess_GenNormals);

        if (!scene || scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE || !scene->mRootNode) {
            std::cerr << "Error loading model: " << importer.GetErrorString() << std::endl;
            return;
        }

        processNode(scene->mRootNode, scene, scale);
    }

    void processNode(aiNode* node, const aiScene* scene, float scale) {
        for (unsigned int i = 0; i < node->mNumMeshes; ++i) {
            aiMesh* mesh = scene->mMeshes[node->mMeshes[i]];
            meshes.push_back(processMesh(mesh, scale));
        }

        for (unsigned int i = 0; i < node->mNumChildren; ++i) {
            processNode(node->mChildren[i], scene, scale);
        }
    }

    Mesh processMesh(aiMesh* mesh, float scale) {
        Mesh resultMesh;

        for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
            resultMesh.vertices.emplace_back(
                mesh->mVertices[i].x * scale,
                mesh->mVertices[i].y * scale,
                mesh->mVertices[i].z * scale
                );
        }

        return resultMesh;
    }

private:
    std::vector<Mesh> meshes;
    glm::vec3 position;
};
#endif
