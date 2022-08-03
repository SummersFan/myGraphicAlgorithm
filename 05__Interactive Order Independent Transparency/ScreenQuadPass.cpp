#include "ScreenQuadPass.h"
#include "Interface.h"
#include "Shader.h"
#include "Utils.h"
#include <GLFW/glfw3.h>

_ScreenQuadPass::_ScreenQuadPass(const std::string& vPassName, int vExecutionOrder) : _RenderPass(vPassName, vExecutionOrder)
{
}

_ScreenQuadPass::~_ScreenQuadPass()
{
}

//************************************************************************************
//Function:
void _ScreenQuadPass::initV()
{
	m_pShader = std::make_shared<_Shader>("ScreenQuad_VS.glsl", "ScreenQuad_FS.glsl");

	m_pShader->activeShader();
	m_pShader->setTextureUniformValue("u_ShadingTexture", MyGraphics::ResourceManager::getSharedDataByName<std::shared_ptr<MyGraphics::STexture>>("ShadingTexture"));

}

//************************************************************************************
//Function:
void _ScreenQuadPass::updateV()
{

	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClearColor(1, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);
	m_pShader->activeShader();
	drawQuad();
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	if (MyGraphics::InputManager::getKeyStatus(GLFW_KEY_M) == GLFW_PRESS && m_OldKeyMStatusSave != GLFW_PRESS)
	{
		m_OldKeyMStatusSave = GLFW_PRESS;
		captureScreen2Img("SponzaGlossyToDiffuseGGX.png");
		std::cout << "Save Image" << std::endl;
	}
	else if (MyGraphics::InputManager::getKeyStatus(GLFW_KEY_M) == GLFW_RELEASE)
		m_OldKeyMStatusSave = GLFW_RELEASE;

}