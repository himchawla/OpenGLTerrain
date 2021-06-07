#pragma once

// Project
#include "staticMesh3D.h"

namespace static_meshes_3D {

    /**
     * Represents generic 3D static mesh rendered with indexed rendering.
     */
    class StaticMesh3DIndexed : public StaticMesh3D
    {
    public:
        StaticMesh3DIndexed(bool withPositions, bool withTextureCoordinates, bool withNormals);
        virtual ~StaticMesh3DIndexed();

        void deleteMesh() override;

    protected:
        VertexBufferObject _indicesVBO; // Our VBO wrapper class holding indices data

        int _numVertices = 0; // Holds the total number of generated vertices
        int _numIndices = 0; // Holds the number of generated indices used for rendering
        int _primitiveRestartIndex = 0; // Index of primitive restart
    };

}; // namespace static_meshes_3D