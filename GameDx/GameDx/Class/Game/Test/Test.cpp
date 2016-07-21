#include "Class\Game\Test\Test.h"
#include "Class\Framework\Camera.h"
#include "Class\Framework\Timer.h"

Test::Test(LPDIRECT3DDEVICE9 device)
{
	m_SpriteTest	= new CSprite(L"Resource//Test//BOX_OPENED.png", 1, 3, 3, 0);
	m_position = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	m_StaticSprite = new CSprite(L"Resource//Image//Game//Sprites//Others//rock.png");
	m_positionStatic = D3DXVECTOR3(200.0f, 0.0f, 0.0f);

	RECT rect		= {	
						m_position.x,
						m_position.y,
						m_position.x + (m_SpriteTest->getScrRect().right - m_SpriteTest->getScrRect().left),
						m_position.y + (m_SpriteTest->getScrRect().top - m_SpriteTest->getScrRect().bottom)
					  };

	m_Bounding		= new CBox2D(device, rect, vector2dZero);

	//m_StaticObject->m_Bounding = new CBox2D(m_StaticObject->getBounding());
}

Test::~Test()
{
	SAFE_RELEASE(m_SpriteTest);
	SAFE_RELEASE(m_Text);
	SAFE_RELEASE(m_Bounding);

	SAFE_RELEASE(m_StaticSprite);
	SAFE_RELEASE(m_StaticObject);
}

void Test::Update(CKeyBoard* device)
{

	if (device->KeyDown(DIK_RIGHT))
		this->m_position.x += 5;

	if (device->KeyDown(DIK_LEFT))
		this->m_position.x -= 5;

	if (device->KeyDown(DIK_UP))
		this->m_position.y += 5;

	if (device->KeyDown(DIK_DOWN))

		this->m_position.y -= 5;



	m_Bounding->update(CTimer::getInstance()->getElapedTime(), vector2d(m_position.x, m_position.y));

}

void Test::Render()
{
	m_SpriteTest->Render(CCamera::setPositionEntity(m_position), vector2d(1.0f, 1.0f), 0.0f, DRAWCENTER_LEFT_TOP);
	m_StaticSprite->Render(CCamera::setPositionEntity(m_positionStatic), vector2d(1.0, 1.0), 0.0f, DRAWCENTER_MIDDLE_MIDDLE, true);
}

D3DXVECTOR3 Test::getPosision()
{
	return m_position;
}
