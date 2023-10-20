#ifndef TEXTURE_STRUCT_H
#define TEXTURE_STRUCT_H

struct Texture
{
    Texture() {
        textureCoords[0] = 0;
        textureCoords[1] = 1;
        textureCoords[2] = 0;
        textureCoords[3] = 0;
        textureCoords[4] = 1;
        textureCoords[5] = 0;
        textureCoords[6] = 1;
        textureCoords[7] = 1;
    }

    unsigned int texture;
    float textureCoords[8];
};

#endif // TEXTURE_STRUCT_H
