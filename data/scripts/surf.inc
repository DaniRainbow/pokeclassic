EventScript_UseSurf::
	goto_if_unset FLAG_BADGE05_GET, EventScript_ScarySeas
	checkpartymove MOVE_SURF
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_EndUseSurf
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	lockall
	msgbox gText_WantToUseSurf, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_ReleaseUseSurf
	msgbox gText_PlayerUsedSurf, MSGBOX_DEFAULT
	dofieldeffect FLDEFF_USE_SURF
EventScript_ReleaseUseSurf::
	releaseall
EventScript_EndUseSurf::
	end

EventScript_ScarySeas::
	msgbox EventScript_ScarySeasText, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

EventScript_ScarySeasText:
	.string "The water before you looks inviting.\p"
	.string "Perhaps surfing is in your future.$"

