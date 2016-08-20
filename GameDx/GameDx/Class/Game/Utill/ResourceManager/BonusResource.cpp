#include "BonusResource.h"
#include "Class\Game\Utill\stdafx.h"

CBonusResource::CBonusResource()
{
}

CBonusResource::CBonusResource(int type) {
	m_TypeObject = type;
}

CBonusResource::~CBonusResource()
{
}

wchar_t* CBonusResource::getImage(int tag, int state) {
	switch (tag)
	{
	case TAGNODE::STAR:
		return  L"Resource//Image//Game//Sprites//Mario//Bonus//star.png";
	case TAGNODE::BRICK:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//gach.png";
	case TAGNODE::RED_MUSHROOM:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//nam_do_nho.png";
	case TAGNODE::GREEN_MUSHROOM:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//nam_xanh_nho.png";
	case TAGNODE::COIN:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//coin_dung.png";
	case TAGNODE::COININBOX:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//coin_xoay.png";
	case TAGNODE::GIFT_BOX:
		switch (state)
		{
		case GIFTBOX_STATE::GIFTBOX_NORMAL:
			return L"Resource//Image//Game//Sprites//Mario//Bonus//gach_cham_hoi.png";
		case GIFTBOX_STATE::GIFTBOX:
			return L"Resource//Image//Game//Sprites//Mario//Bonus//gach_mat_cham_hoi.png";
		default:
			break;
		}
	case TAGNODE::FLOWER:
		return L"Resource//Image//Game//Sprites//Mario//Bonus//hoa.png";
	case TAGNODE::BRICKMINI:
		switch (state)
		{
		case BRICKMINI_TYPE::BRICKMINI_LEFT_DOWN:case BRICKMINI_TYPE::BRICKMINI_RIGHT_DOWN:
			return L"Resource//Image//Game//Sprites//Mario//Bonus//gach_vo_phai.png";
		case BRICKMINI_TYPE::BRICKMINI_LEFT_UP: case BRICKMINI_TYPE::BRICKMINI_RIGHT_UP:
			return L"Resource//Image//Game//Sprites//Mario//Bonus//gach_vo_trai.png";
		default:
			break;
		}
	default:
		break;
	}
}
