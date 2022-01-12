#include "../include/disk_object.h"

#include "../include/demo_application.h"

DiskObject::DiskObject() {
    m_radius = 0.0f;
}

DiskObject::~DiskObject() {
    /* void */
}

void DiskObject::initialize(atg_scs::RigidBodySystem *system) {
    DemoObject::initialize(system);

    system->addRigidBody(&m_body);
}

void DiskObject::reset() {
    DemoObject::reset();

    m_body.reset();
}

void DiskObject::render(DemoApplication *app) {
    DemoObject::render(app);

    app->drawDisk(m_body.p_x, m_body.p_y, m_body.theta, m_radius);
}

void DiskObject::process(float dt, DemoApplication *app) {
    DemoObject::process(dt, app);
}

void DiskObject::configure(float radius, float density) {
    m_radius = radius;

    m_body.m = density * (double)ysMath::Constants::PI * radius * radius;
    m_body.I = 0.5 * m_body.m * radius * radius;
}
