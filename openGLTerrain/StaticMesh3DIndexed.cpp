// Project
#include "staticMesh3DIndexed.h"

namespace static_meshes_3D {

    StaticMesh3DIndexed::StaticMesh3DIndexed(bool withPositions, bool withTextureCoordinates, bool withNormals)
        : StaticMesh3D(withPositions, withTextureCoordinates, withNormals) {}

    StaticMesh3DIndexed::~StaticMesh3DIndexed()
    {
        if (_isInitialized) {
            // It's enough to delete indices VBO here, rest of stuff is destructed in super destructor
            _indicesVBO.deleteVBO();
        }
    }

    void StaticMesh3DIndexed::deleteMesh()
    {
        if (_isInitialized) {
            _indicesVBO.deleteVBO();
            StaticMesh3D::deleteMesh();
        }
    }

} // namespace static_meshes_3D