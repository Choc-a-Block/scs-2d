#ifndef ATG_SCS_2D_DEMO_DEMO_APPLICATION_H
#define ATG_SCS_2D_DEMO_DEMO_APPLICATION_H

#include "geometry_generator.h"

#include "delta.h"

class DemoApplication {
public:
    enum class Application {
        SimplePendulum,
        DoublePendulum,
        ArticulatedPendulum,
        LineConstraintPendulum
    };

public:
    DemoApplication();
    virtual ~DemoApplication();

    static DemoApplication *createApplication(Application application);

    void initialize(void *instance, ysContextObject::DeviceAPI api);
    void run();
    void destroy();

    void setCameraPosition(const ysVector &position) { m_cameraPosition = position; }
    void setCameraTarget(const ysVector &target) { m_cameraTarget = target; }
    void setCameraUp(const ysVector &up) { m_cameraUp = up; }

    void drawGenerated(const GeometryGenerator::GeometryIndices &indices);

protected:
    void renderScene();

protected:
    virtual void initialize();
    virtual void process(float dt);
    virtual void render();

    dbasic::ShaderSet m_shaderSet;
    dbasic::DefaultShaders m_shaders;

    dbasic::DeltaEngine m_engine;
    dbasic::AssetManager m_assetManager;

    ysVector m_cameraPosition;
    ysVector m_cameraTarget;
    ysVector m_cameraUp;

    std::string m_assetPath;

    ysGPUBuffer *m_geometryVertexBuffer;
    ysGPUBuffer *m_geometryIndexBuffer;

    GeometryGenerator m_geometryGenerator;
};

#endif /* ATG_SCS_2D_DEMO_DEMO_APPLICATION_H */
