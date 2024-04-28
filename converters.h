#pragma once

#include <Windows.h>

extern "C" {
	void PS3Wii_RockBand_ToGip(const BYTE* ps3rb_buf, BYTE* gip_buf);
	void Santroller_RockBand_ToGip(const BYTE* san_buf, BYTE* gip_buf);
	void Santroller_GuitarHero_ToGip(const BYTE* san_buf, BYTE* gip_buf);
	void PS3_GuitarHero_ToGip(const BYTE* ps3gh_buf, BYTE* gip_buf);
	void PS4_RockBand_ToGip(const BYTE* ps4rb_buf, BYTE* gip_buf);
	void XInput_RockBand_ToGip(const BYTE* xinput_buf, BYTE* gip_buf);
	void XInput_GuitarHero_ToGip(const BYTE* xinput_buf, BYTE* gip_buf);
	void Raphnet_GuitarHero_ToGip(const BYTE* raph_buf, BYTE* gip_buf);
	void XInput_Guitar_ToGip(const BYTE* xinput_buf, BYTE* gip_buf);
	void XInput_Wireless_ToGip(const BYTE* xinput_buf, BYTE* gip_buf);
}
