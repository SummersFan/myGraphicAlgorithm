#include "LightCamera.h"
#include "Interface.h"
#include <glm/gtc/matrix_transform.hpp>

_LightCamera::_LightCamera(const std::string& vGameObjectName, int vExecutionOrder) : _GameObject(vGameObjectName, vExecutionOrder)
{
}

_LightCamera::~_LightCamera()
{
}

void _LightCamera::initV()
{
	m_LightPos = MyGraphics::ResourceManager::getSharedDataByName<glm::vec3>("LightPos");
	m_LightDir = MyGraphics::ResourceManager::getSharedDataByName<glm::vec3>("LightDir");

	if (abs(m_LightDir) == m_LightUpVector)
		m_LightDir.z += 0.01f;
	m_LightViewMatrix = glm::lookAt(m_LightPos, m_LightPos + m_LightDir, m_LightUpVector);
	m_LightProjectionMatrix = glm::ortho(-m_CameraSizeExtent, m_CameraSizeExtent, -m_CameraSizeExtent, m_CameraSizeExtent, 0.1f, 1000.0f);
	MyGraphics::ResourceManager::registerSharedData("LightViewMatrix", m_LightViewMatrix);
	MyGraphics::ResourceManager::registerSharedData("LightProjectionMatrix", m_LightProjectionMatrix);
	MyGraphics::ResourceManager::registerSharedData("LightCameraAreaInWorldSpace", (2.0f * m_CameraSizeExtent)*(2.0f * m_CameraSizeExtent));
}

void _LightCamera::updateV()
{
#ifdef _DEBUG
	m_LightDir = MyGraphics::ResourceManager::getSharedDataByName<glm::vec3>("LightDir");
	m_LightPos = MyGraphics::ResourceManager::getSharedDataByName<glm::vec3>("LightPos");
	if (abs(m_LightDir) == m_LightUpVector)
		m_LightDir.z += 0.01f;
	m_LightViewMatrix = glm::lookAt(m_LightPos, m_LightPos + m_LightDir, m_LightUpVector);
	m_LightProjectionMatrix = glm::ortho(-m_CameraSizeExtent, m_CameraSizeExtent, -m_CameraSizeExtent, m_CameraSizeExtent, 0.1f, 1000.0f);
	MyGraphics::ResourceManager::updateSharedDataByName("LightViewMatrix", m_LightViewMatrix);
	MyGraphics::ResourceManager::updateSharedDataByName("LightProjectionMatrix", m_LightProjectionMatrix);
#endif
}