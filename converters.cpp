#include <Windows.h>
#include "PlasticBand-structs.h"

extern "C" {

	__declspec(dllexport) void PS3Wii_RockBand_ToGip(const BYTE* ps3rb_buf, BYTE* gip_buf) {
		PS3RockBandGuitarState* ps3rb = (PS3RockBandGuitarState*)ps3rb_buf;
		GipGuitarState* gip = (GipGuitarState*)gip_buf;

		// cram the ps button into an unused bit
		gip->unused = ps3rb->ps;

		gip->green = gip->greenFlag = ps3rb->green;
		gip->red = gip->redFlag = ps3rb->red;
		gip->yellow = gip->yellowFlag = ps3rb->yellow;
		gip->blue = gip->blueFlag = ps3rb->blue;
		gip->orange = gip->orangeFlag = ps3rb->orange;

		gip->menu = ps3rb->start;
		gip->view = ps3rb->select;

		gip->whammy = ps3rb->whammy;
		gip->tilt = ps3rb->tilt ? 0xFF : 0x00;

		gip->dpadLeft = ps3rb->dpad_strum == 6;
		gip->dpadRight = ps3rb->dpad_strum == 2;
		gip->dpadStrumUp = ps3rb->dpad_strum == 0;
		gip->dpadStrumDown = ps3rb->dpad_strum == 4;

		// TODO: solo buttons and effects slider. unused in festival but would be fun
	}

	__declspec(dllexport) void Santroller_RockBand_ToGip(const BYTE* san_buf, BYTE* gip_buf) {
		SantrollerRockBandGuitarState* san = (SantrollerRockBandGuitarState*)san_buf;
		GipGuitarState* gip = (GipGuitarState*)gip_buf;

		// cram the ps button into an unused bit
		gip->unused = san->home;

		gip->green = gip->greenFlag = san->green;
		gip->red = gip->redFlag = san->red;
		gip->yellow = gip->yellowFlag = san->yellow;
		gip->blue = gip->blueFlag = san->blue;
		gip->orange = gip->orangeFlag = san->orange;

		gip->menu = san->start;
		gip->view = san->select;

		gip->whammy = san->whammy;
		gip->tilt = san->tilt;

		gip->dpadLeft = san->dpad_strum == 6;
		gip->dpadRight = san->dpad_strum == 2;
		gip->dpadStrumUp = san->dpad_strum == 0;
		gip->dpadStrumDown = san->dpad_strum == 4;

		// TODO: solo buttons and effects slider. unused in festival but would be fun
	}

	__declspec(dllexport) void Santroller_GuitarHero_ToGip(const BYTE* san_buf, BYTE* gip_buf) {
		SantrollerGuitarHeroGuitarState* san = (SantrollerGuitarHeroGuitarState*)san_buf;
		GipGuitarState* gip = (GipGuitarState*)gip_buf;

		// cram the ps button into an unused bit
		gip->unused = san->home;

		gip->green = gip->greenFlag = san->green;
		gip->red = gip->redFlag = san->red;
		gip->yellow = gip->yellowFlag = san->yellow;
		gip->blue = gip->blueFlag = san->blue;
		gip->orange = gip->orangeFlag = san->orange;

		gip->menu = san->start;
		gip->view = san->select;

		gip->whammy = san->whammy;
		gip->tilt = san->tilt;

		gip->dpadLeft = san->dpad_strum == 6;
		gip->dpadRight = san->dpad_strum == 2;
		gip->dpadStrumUp = san->dpad_strum == 0;
		gip->dpadStrumDown = san->dpad_strum == 4;

		// TODO: solo buttons and effects slider. unused in festival but would be fun
	}

	__declspec(dllexport) void PS3_GuitarHero_ToGip(const BYTE* ps3gh_buf, BYTE* gip_buf) {
		PS3GuitarHeroGuitarState* ps3gh = (PS3GuitarHeroGuitarState*)ps3gh_buf;
		GipGuitarState* gip = (GipGuitarState*)gip_buf;

		// cram the ps button into an unused bit
		gip->unused = ps3gh->ps;

		gip->green = gip->greenFlag = ps3gh->green;
		gip->red = gip->redFlag = ps3gh->red;
		gip->yellow = gip->yellowFlag = ps3gh->yellow;
		gip->blue = gip->blueFlag = ps3gh->blue;
		gip->orange = gip->orangeFlag = ps3gh->orange;

		gip->menu = ps3gh->start;
		gip->view = ps3gh->select;

		gip->tilt = ps3gh->tilt_accelX > 0x300 ? 0xFF : 0x00;
		gip->whammy = ps3gh->whammy;

		gip->dpadLeft = ps3gh->dpad_strum == 6;
		gip->dpadRight = ps3gh->dpad_strum == 2;
		gip->dpadStrumUp = ps3gh->dpad_strum == 0;
		gip->dpadStrumDown = ps3gh->dpad_strum == 4;
	}

	__declspec(dllexport) void PS4_RockBand_ToGip(const BYTE* ps4rb_buf, BYTE* gip_buf) {
		PS4RockBandGuitarState* ps4rb = (PS4RockBandGuitarState*)ps4rb_buf;
		GipGuitarState* gip = (GipGuitarState*)gip_buf;

		// cram the ps button into an unused bit
		gip->unused = ps4rb->ps;

		gip->green = ps4rb->green;
		gip->red = ps4rb->red;
		gip->yellow = ps4rb->yellow;
		gip->blue = ps4rb->blue;
		gip->orange = ps4rb->orange;

		gip->greenFlag = ps4rb->greenFlag;
		gip->redFlag = ps4rb->redFlag;
		gip->yellowFlag = ps4rb->yellowFlag;
		gip->blueFlag = ps4rb->blueFlag;
		gip->orangeFlag = ps4rb->orangeFlag;

		gip->soloFlag = ps4rb->soloFlag;
		gip->soloGreen = ps4rb->soloGreen;
		gip->soloRed = ps4rb->soloRed;
		gip->soloYellow = ps4rb->soloYellow;
		gip->soloBlue = ps4rb->soloBlue;
		gip->soloOrange = ps4rb->soloOrange;

		gip->menu = ps4rb->options;
		gip->view = ps4rb->share;

		gip->tilt = ps4rb->tilt;
		gip->whammy = ps4rb->whammy;
		gip->pickup = ps4rb->pickup;

		gip->dpadLeft = ps4rb->dpad_strum == 6;
		gip->dpadRight = ps4rb->dpad_strum == 2;
		gip->dpadStrumUp = ps4rb->dpad_strum == 0;
		gip->dpadStrumDown = ps4rb->dpad_strum == 4;
	}

	// TODO: All of these

	/*

	__declspec(dllexport) void XInput_Guitar_ToGip(const BYTE* xinput_buf, BYTE* gip_buf) {

	}

	__declspec(dllexport) void XInput_Wireless_ToGip(const BYTE* xinput_buf, BYTE* gip_buf) {
		XInput_Guitar_ToGip(xinput_buf + 4, gip_buf);
	}
	*/

}
