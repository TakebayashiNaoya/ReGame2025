#include "stdafx.h"
#include "BackGround.h"

bool BackGround::Start()
{
	m_modelRender.Init("Assets/modelData/ReGame_Stage/stage.tkm");
	physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());

	return true;
}

void BackGround::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}