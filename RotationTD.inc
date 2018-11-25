/*

	Author: knox
	Version: 1.0
	Data: 25.11.2018

*/

#if defined _RotationTD_included
	#endinput
#endif

#define _RotationTD_included

#define AXIS_ROT_X 1
#define AXIS_ROT_Y 2
#define AXIS_ROT_Z 3

#define IsTextDrawValid(%0) (_RTD_TextDraw[_:%0][_RTD_VALID] == 1)
#define IsPlayerTextDrawValid(%0) (_RTD_PlayerTextDraw[_:%0][_RTD_VALID] == 1)

enum _RTD_TEXT_DRAW_INFO
{
	_RTD_VALID,
	Float:_RTD_R_X,
	Float:_RTD_R_Y,
	Float:_RTD_R_Z,
	Float:_RTD_R_ZOOM,
	_RTD_FONT,
	_RTD_AXIS,
	Float:_RTD_STEP,
	_RTD_TIMER
};

static
	_RTD_TextDraw[MAX_TEXT_DRAWS][_RTD_TEXT_DRAW_INFO],
	_RTD_TextDrawLook[MAX_TEXT_DRAWS][MAX_PLAYERS],
	_RTD_PlayerTextDraw[MAX_PLAYER_TEXT_DRAWS][_RTD_TEXT_DRAW_INFO]
;

/*
	OnPlayerConnect
*/

public OnPlayerConnect(playerid)
{
	for(new i; i < MAX_TEXT_DRAWS; i++)
	{
		_RTD_TextDrawLook[i][playerid] = 0;
	}

	#if defined _RTD_OnPlayerConnect
		return _RTD_OnPlayerConnect(playerid);
	#else
		return 1;
	#endif
}
#if defined _ALS_OnPlayerConnect
	#undef OnPlayerConnect
#else
	#define _ALS_OnPlayerConnect
#endif

#define OnPlayerConnect _RTD_OnPlayerConnect
#if defined _RTD_OnPlayerConnect
	forward _RTD_OnPlayerConnect(playerid);
#endif

/*
	TextDrawCreate
*/

stock Text:__TextDrawCreateEx(Float:x, Float:y, text[])
{
	static Text:_rtd_temp_td;
	_rtd_temp_td = TextDrawCreate(x, y, text);
	_RTD_TextDraw[_:_rtd_temp_td][_RTD_VALID] = 1;
	_RTD_TextDraw[_:_rtd_temp_td][_RTD_R_X] = 0.0;
	_RTD_TextDraw[_:_rtd_temp_td][_RTD_R_Y] = 0.0;
	_RTD_TextDraw[_:_rtd_temp_td][_RTD_R_Z] = 0.0;
	_RTD_TextDraw[_:_rtd_temp_td][_RTD_R_ZOOM] = 1.0;
	return _rtd_temp_td;
}
#if defined _ALS_TextDrawCreate
	#undef TextDrawCreate
#else
	#define _ALS_TextDrawCreate
#endif
#define TextDrawCreate __TextDrawCreateEx

/*
	TextDrawDestroy
*/

stock __TextDrawDestroy(Text:text)
{
	_RTD_TextDraw[_:text][_RTD_VALID] = 0;
	return TextDrawDestroy(text);
}
#if defined _ALS_TextDrawDestroy
	#undef TextDrawDestroy
#else
	#define _ALS_TextDrawDestroy
#endif
#define TextDrawDestroy __TextDrawDestroy

/*
	TextDrawFont
*/

stock __TextDrawFont(Text:text, font)
{
	_RTD_TextDraw[_:text][_RTD_FONT] = font;
	return TextDrawFont(text, font);
}
#if defined _ALS_TextDrawFont
	#undef TextDrawFont
#else
	#define _ALS_TextDrawFont
#endif
#define TextDrawFont __TextDrawFont

/*
	TextDrawShowForPlayer
*/

stock __TextDrawShowForPlayer(playerid, Text:text)
{
	_RTD_TextDrawLook[_:text][playerid] = 1;
	return TextDrawShowForPlayer(playerid, text);
}
#if defined _ALS_TextDrawShowForPlayer
	#undef TextDrawShowForPlayer
#else
	#define _ALS_TextDrawShowForPlayer
#endif
#define TextDrawShowForPlayer __TextDrawShowForPlayer

/*
	TextDrawHideForPlayer
*/

stock __TextDrawHideForPlayer(playerid, Text:text)
{
	_RTD_TextDrawLook[_:text][playerid] = 0;
	return TextDrawHideForPlayer(playerid, text);
}
#if defined _ALS_TextDrawHideForPlayer
	#undef TextDrawHideForPlayer
#else
	#define _ALS_TextDrawHideForPlayer
#endif
#define TextDrawHideForPlayer __TextDrawHideForPlayer

/*
	TextDrawSetPreviewRot
*/

stock __TextDrawSetPreviewRot(Text:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0)
{
	_RTD_TextDraw[_:text][_RTD_R_X] = fRotX;
	_RTD_TextDraw[_:text][_RTD_R_Y] = fRotY;
	_RTD_TextDraw[_:text][_RTD_R_Z] = fRotZ;
	_RTD_TextDraw[_:text][_RTD_R_ZOOM] = fZoom;
	return TextDrawSetPreviewRot(Text:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0);
}
#if defined _ALS_TextDrawSetPreviewRot
	#undef TextDrawSetPreviewRot
#else
	#define _ALS_TextDrawSetPreviewRot
#endif
#define TextDrawSetPreviewRot __TextDrawSetPreviewRot

// - Player Text Draws

/*
	CreatePlayerTextDraw
*/

stock PlayerText:__CreatePlayerTextDraw(playerid, Float:x, Float:y, text[])
{
	static PlayerText:_rtd_temp_ptd;
	_rtd_temp_ptd = CreatePlayerTextDraw(playerid, x, y, text);
	_RTD_PlayerTextDraw[_:_rtd_temp_ptd][_RTD_VALID] = 1;
	_RTD_PlayerTextDraw[_:_rtd_temp_ptd][_RTD_R_X] = 0.0;
	_RTD_PlayerTextDraw[_:_rtd_temp_ptd][_RTD_R_Y] = 0.0;
	_RTD_PlayerTextDraw[_:_rtd_temp_ptd][_RTD_R_Z] = 0.0;
	_RTD_PlayerTextDraw[_:_rtd_temp_ptd][_RTD_R_ZOOM] = 1.0;
	return _rtd_temp_ptd;
}
#if defined _ALS_CreatePlayerTextDraw
	#undef CreatePlayerTextDraw
#else
	#define _ALS_CreatePlayerTextDraw
#endif
#define CreatePlayerTextDraw __CreatePlayerTextDraw

/*
	PlayerTextDrawDestroy
*/

stock __PlayerTextDrawDestroy(playerid, PlayerText:text)
{
	_RTD_PlayerTextDraw[_:text][_RTD_VALID] = 0;
	return  PlayerTextDrawDestroy(playerid, text);
}
#if defined _ALS_PlayerTextDrawDestroy
	#undef PlayerTextDrawDestroy
#else
	#define _ALS_PlayerTextDrawDestroy
#endif
#define PlayerTextDrawDestroy __PlayerTextDrawDestroy

/*
	PlayerTextDrawFont
*/

stock __PlayerTextDrawFont(playerid, PlayerText:text, font)
{
	_RTD_PlayerTextDraw[_:text][_RTD_FONT] = font;
	return PlayerTextDrawFont(playerid, text, font);
}
#if defined _ALS_PlayerTextDrawFont
	#undef PlayerTextDrawFont
#else
	#define _ALS_PlayerTextDrawFont
#endif
#define PlayerTextDrawFont __PlayerTextDrawFont

/*
	PlayerTextDrawSetPreviewRot
*/

stock __PlayerTextDrawSetPreviewRot(playerid, PlayerText:text, Float:fRotX, Float:fRotY, Float:fRotZ, Float:fZoom = 1.0)
{
	_RTD_PlayerTextDraw[_:text][_RTD_R_X] = fRotX;
	_RTD_PlayerTextDraw[_:text][_RTD_R_Y] = fRotY;
	_RTD_PlayerTextDraw[_:text][_RTD_R_Z] = fRotZ;
	_RTD_PlayerTextDraw[_:text][_RTD_R_ZOOM] = fZoom;
	return PlayerTextDrawSetPreviewRot(playerid, text, fRotX, fRotY, fRotZ, fZoom);
}
#if defined _ALS_PlayerTDSetPreviewRot
	#undef PlayerTextDrawSetPreviewRot
#else
	#define _ALS_PlayerTDSetPreviewRot
#endif
#define PlayerTextDrawSetPreviewRot __PlayerTextDrawSetPreviewRot

// - include function

stock TextDrawStartRot(Text:text, axis_rot = AXIS_ROT_X, speed_rot = 500, Float:step_rot = 20.0)
{
	static textid;
	if(!IsTextDrawValid(text)) return 0;
	textid = _:text;
	_RTD_TextDraw[textid][_RTD_AXIS] = axis_rot;
	_RTD_TextDraw[textid][_RTD_STEP] = step_rot;
	_RTD_TextDraw[textid][_RTD_TIMER] = SetTimerEx("_RTD_UpdateTextDraw", speed_rot, true, "d", textid);
	_RTD_TextDrawStep(text, axis_rot, step_rot);
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if(_RTD_TextDrawLook[textid][i] == 0) continue;
		TextDrawHideForPlayer(i, text);
		TextDrawShowForPlayer(i, text);
	}
	return 1;
}

stock PlayerTextDrawStartRot(playerid, PlayerText:text, axis_rot = AXIS_ROT_X, speed_rot = 500, Float:step_rot = 20.0)
{
	static textid;
	if(!IsPlayerTextDrawValid(text)) return 0;
	textid = _:text;
	_RTD_PlayerTextDraw[textid][_RTD_AXIS] = axis_rot;
	_RTD_PlayerTextDraw[textid][_RTD_STEP] = step_rot;
	_RTD_PlayerTextDraw[textid][_RTD_TIMER] = SetTimerEx("_RTD_UpdatePlayerTextDraw", speed_rot, true, "dd", playerid, textid);
	_RTD_PlayerTextDrawStep(playerid, text, axis_rot, step_rot);
	PlayerTextDrawRender(playerid, text);
	return 1;
}

stock PlayerTextDrawStopRot(PlayerText:text)
{
	KillTimer(_RTD_PlayerTextDraw[_:text][_RTD_TIMER]);
	_RTD_PlayerTextDraw[_:text][_RTD_AXIS] = 0;
	_RTD_PlayerTextDraw[_:text][_RTD_STEP] = 0.0;
	return 1;
}

// - other function

forward _RTD_UpdateTextDraw(playerid, textid);
public _RTD_UpdateTextDraw(playerid, textid)
{
	if(!IsPlayerConnected(playerid) || !IsTextDrawValid(Text:textid)) {
		KillTimer(_RTD_TextDraw[textid][_RTD_TIMER]);
		_RTD_TextDraw[textid][_RTD_AXIS] = 0;
		_RTD_TextDraw[textid][_RTD_STEP] = 0.0;
		return 0;
	}
	_RTD_TextDrawStep(Text:textid, _RTD_TextDraw[textid][_RTD_AXIS], _RTD_TextDraw[textid][_RTD_STEP]);
	for(new i; i < MAX_PLAYERS; i++)
	{
		if(!IsPlayerConnected(i)) continue;
		if(_RTD_TextDrawLook[textid][i] == 0) continue;
		TextDrawHideForPlayer(i, Text:textid);
		TextDrawShowForPlayer(i, Text:textid);
	}
	return 1;
}

static stock _RTD_TextDrawStep(Text:text, axis_rot, Float:step_rot)
{
	if(!IsTextDrawValid(text)) return 0;
	switch(axis_rot)
	{
		case AXIS_ROT_X: _RTD_LimitRotationStep(_RTD_TextDraw[_:text][_RTD_R_X], step_rot);
		case AXIS_ROT_Y: _RTD_LimitRotationStep(_RTD_TextDraw[_:text][_RTD_R_Y], step_rot);
		case AXIS_ROT_Z: _RTD_LimitRotationStep(_RTD_TextDraw[_:text][_RTD_R_Z], step_rot);
		default: return 0;
	}
	TextDrawSetPreviewRot(text, _RTD_TextDraw[_:text][_RTD_R_X], _RTD_TextDraw[_:text][_RTD_R_Y],
		_RTD_TextDraw[_:text][_RTD_R_Z], _RTD_TextDraw[_:text][_RTD_R_ZOOM]
	);
	return 1;
}

forward _RTD_UpdatePlayerTextDraw(playerid, textid);
public _RTD_UpdatePlayerTextDraw(playerid, textid)
{
	if(!IsPlayerConnected(playerid) || !IsPlayerTextDrawValid(PlayerText:textid)) {
		KillTimer(_RTD_PlayerTextDraw[textid][_RTD_TIMER]);
		_RTD_PlayerTextDraw[textid][_RTD_AXIS] = 0;
		_RTD_PlayerTextDraw[textid][_RTD_STEP] = 0.0;
		return 0;
	}
	_RTD_PlayerTextDrawStep(playerid, PlayerText:textid, _RTD_PlayerTextDraw[textid][_RTD_AXIS], _RTD_PlayerTextDraw[textid][_RTD_STEP]);
	PlayerTextDrawRender(playerid, PlayerText:textid);
	return 1;
}

static stock _RTD_PlayerTextDrawStep(playerid, PlayerText:text, axis_rot, Float:step_rot)
{
	if(!IsPlayerTextDrawValid(text)) return 0;
	switch(axis_rot)
	{
		case AXIS_ROT_X: _RTD_LimitRotationStep(_RTD_PlayerTextDraw[_:text][_RTD_R_X], step_rot);
		case AXIS_ROT_Y: _RTD_LimitRotationStep(_RTD_PlayerTextDraw[_:text][_RTD_R_Y], step_rot);
		case AXIS_ROT_Z: _RTD_LimitRotationStep(_RTD_PlayerTextDraw[_:text][_RTD_R_Z], step_rot);
		default: return 0;
	}
	PlayerTextDrawSetPreviewRot(playerid, text, _RTD_PlayerTextDraw[_:text][_RTD_R_X], _RTD_PlayerTextDraw[_:text][_RTD_R_Y],
		_RTD_PlayerTextDraw[_:text][_RTD_R_Z], _RTD_PlayerTextDraw[_:text][_RTD_R_ZOOM]
	);
	return 1;
}

static stock _RTD_LimitRotationStep(&Float:rot, Float:step_rot)
{
	rot += step_rot;
	if(rot > 360 || rot < 0) {
		rot = float(floatround(rot) % 360);
	}
	return 1;
}

stock PlayerTextDrawRender(playerid, PlayerText:text)
{
	PlayerTextDrawHide(playerid, text);
	PlayerTextDrawShow(playerid, text);
	return 1;
}

