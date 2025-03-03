#pragma once

#include "Setting.hpp"
#include "SettingCollectionList.hpp"

class INISettingCollection : public SettingCollectionList<Setting> {
public:
	static INISettingCollection* GetSingleton();

	struct AnimationWarning {
		static Setting* const bClampWarning;
		static Setting* const bPriorityWarning;
	};

	struct Archive {
		static Setting* const bCheckRuntimeCollisions;
		static Setting* const bInvalidateOlderFiles;
		static Setting* const bUseArchives;

		static Setting* const iRetainDirectoryStringTable;
		static Setting* const iRetainFilenameOffsetTable;
		static Setting* const iRetainFilenameStringTable;

		static Setting* const sArchiveList;
		static Setting* const sInvalidationFile;
	};

	struct Audio {
		static Setting* const bEnableAudio;
		static Setting* const bEnableAudioCache;
		static Setting* const bEnableEnviroEffectsOnPC;
		static Setting* const bMultiThreadAudio;
		static Setting* const bUseAudioDebugInformation;

		static Setting* const iAttenuationDialogMenuMute;
		static Setting* const iAttenuationEffectiveSilence;
		static Setting* const iAudioCacheSize;
		static Setting* const iAudioHWThread;
		static Setting* const iCollisionSoundTimeDelta;
		static Setting* const iMaxFX;
		static Setting* const iMaxImpactSoundCount;
		static Setting* const iMaxSizeForCachedSound;
		static Setting* const iMusicSynchOverride;
		static Setting* const iMusicTransitionInMS;
		static Setting* const iRadioStationTimeout;
		static Setting* const iRadioUpdateInterval;
		static Setting* const iVoiceDecodeBufferSize;

		static Setting* const fASFadeInTime;
		static Setting* const fASFadeOutTime;
		static Setting* const fASFadeStartTime;
		static Setting* const fAudioDebugDelay;
		static Setting* const fChainLargeMassMin;
		static Setting* const fChainMediumMassMin;
		static Setting* const fCollisionSoundHeavyThreshold;
		static Setting* const fCreatureRadioMax;
		static Setting* const fCreatureRadioMin;
		static Setting* const fDBVoiceAttenuationIn2D;
		static Setting* const fDawnTime;
		static Setting* const fDayTime;
		static Setting* const fDialogHitSoundCooldownMax;
		static Setting* const fDialogHitSoundCooldownMin;
		static Setting* const fDialogMaxDistance;
		static Setting* const fDialogMinDistance;
		static Setting* const fDialogueFadeDecibels;
		static Setting* const fDialogueFadeSecondsIn;
		static Setting* const fDialogueFadeSecondsOut;
		static Setting* const fDialogueHeadPitchExaggeration;
		static Setting* const fDialogueHeadRollExaggeration;
		static Setting* const fDialogueHeadYawExaggeration;
		static Setting* const fDuskTime;
		static Setting* const fEarthLargeMassMin;
		static Setting* const fEarthMediumMassMin;
		static Setting* const fFilterDistortionGain;
		static Setting* const fFilterPEQGain;
		static Setting* const fFilterdBAttenuation;
		static Setting* const fGlassLargeMassMin;
		static Setting* const fGlassMediumMassMin;
		static Setting* const fHardLandingDamageThreshold;
		static Setting* const fLargeWeaponSpeedMax;
		static Setting* const fLargeWeaponWeightMin;
		static Setting* const fMainMenuMusicVolume;
		static Setting* const fMasterVolumeMult;
		static Setting* const fMaxFootstepDistance;
		static Setting* const fMediumWeaponSpeedMax;
		static Setting* const fMediumWeaponWeightMin;
		static Setting* const fMetalLargeMassMin;
		static Setting* const fMetalMediumMassMin;
		static Setting* const fMinSoundVel;
		static Setting* const fNightTime;
		static Setting* const fPlayerFootVolume;
		static Setting* const fRadioDialogMute;
		static Setting* const fRadioStaticAtOuterRadiusPct;
		static Setting* const fRegionLoopFadeInTime;
		static Setting* const fRegionLoopFadeOutTime;
		static Setting* const fSkinLargeMassMin;
		static Setting* const fSkinMediumMassMin;
		static Setting* const fStoneLargeMassMin;
		static Setting* const fStoneMediumMassMin;
		static Setting* const fWoodLargeMassMin;
		static Setting* const fWoodMediumMassMin;
	};

	struct BackgroundLoad {
		static Setting* const bBackgroundCellLoads;
		static Setting* const bBackgroundLoadLipFiles;
		static Setting* const bLoadBackgroundFaceGen;
		static Setting* const bLoadHelmetsInBackground;
		static Setting* const bSelectivePurgeUnusedOnFastTravel;
		static Setting* const bUseBackgroundFileLoader;
		static Setting* const bUseMultiThreadedFaceGen;
		static Setting* const bUseMultiThreadedTrees;

		static Setting* const iAnimationClonePerLoop;
		static Setting* const iPostProcessMilliseconds;
		static Setting* const iPostProcessMillisecondsEditor;
		static Setting* const iPostProcessMillisecondsLoadingQueuedPriority;
		static Setting* const iPostProcessTaskWarningMilliseconds;
	};

	struct bLightAttenuation {
		static Setting* const bOutQuadInLin;
		static Setting* const bUseConstant;
		static Setting* const bUseLinear;
		static Setting* const bUseQuadratic;

		static Setting* const uLinearMethod;
		static Setting* const uQuadraticMethod;

		static Setting* const fConstantValue;
		static Setting* const fFlickerMovement;
		static Setting* const fLinearRadiusMult;
		static Setting* const fLinearValue;
		static Setting* const fQuadraticRadiusMult;
		static Setting* const fQuadraticValue;
	};

	struct BlurShaderHDRInterior {
		static Setting* const iNumBlurpasses;

		static Setting* const fBlurRadius;
		static Setting* const fBrightClamp;
		static Setting* const fBrightScale;
		static Setting* const fEmissiveHDRMult;
		static Setting* const fEyeAdaptSpeed;
		static Setting* const fTargetLUM;
		static Setting* const fUpperLUMClamp;
	};

	struct BlurShaderHDR {
		static Setting* const iBlendType;
		static Setting* const iNumBlurpasses;

		static Setting* const fBlurRadius;
		static Setting* const fBrightClamp;
		static Setting* const fBrightScale;
		static Setting* const fEmissiveHDRMult;
		static Setting* const fEyeAdaptSpeed;
		static Setting* const fGrassDimmer;
		static Setting* const fSIEmmisiveMult;
		static Setting* const fSISpecularMult;
		static Setting* const fSkyBrightness;
		static Setting* const fSunBrightness;
		static Setting* const fSunlightDimmer;
		static Setting* const fTargetLUM;
		static Setting* const fTreeDimmer;
		static Setting* const fUpperLUMClamp;
	};

	struct BlurShader {
		static Setting* const iBlendType;
		static Setting* const iBlurTexSize;
		static Setting* const iNumBlurpasses;

		static Setting* const fAlphaAddExterior;
		static Setting* const fAlphaAddInterior;
		static Setting* const fBlurRadius;
		static Setting* const fSIEmmisiveMult;
		static Setting* const fSISpecularMult;
		static Setting* const fSkyBrightness;
		static Setting* const fSunBrightness;
		static Setting* const fSunlightDimmer;
	};

	struct BudgetCaps {
		static Setting* const bIncludeWaterInMNumberCalculations;

		static Setting* const uActiveRefCount;
		static Setting* const uActiveRefCountInterior;
		static Setting* const uActorMemoryBudgetCap;
		static Setting* const uActorRefCount;
		static Setting* const uActorRefCountInterior;
		static Setting* const uAnimatedObjectsCount;
		static Setting* const uAnimatedObjectsCountInterior;
		static Setting* const uCityLODBudgetAdjustment;
		static Setting* const uDecalCount;
		static Setting* const uDecalCountInterior;
		static Setting* const uEmittersCount;
		static Setting* const uEmittersCountInterior;
		static Setting* const uGeometryCount;
		static Setting* const uGeometryCountInterior;
		static Setting* const uGeometryMemory;
		static Setting* const uGeometryMemoryInterior;
		static Setting* const uHavokTriCount;
		static Setting* const uHavokTriCountInterior;
		static Setting* const uLightCount;
		static Setting* const uLightCountInterior;
		static Setting* const uLightExcessGeometry;
		static Setting* const uLightExcessGeometryInterior;
		static Setting* const uLoadedAreaNonActorMemoryBudgetCap;
		static Setting* const uParticlesCount;
		static Setting* const uParticlesCountInterior;
		static Setting* const uRefCount;
		static Setting* const uRefCountInterior;
		static Setting* const uTextureMemory;
		static Setting* const uTextureMemoryInterior;
		static Setting* const uTriangleCount;
		static Setting* const uTriangleCountInterior;
		static Setting* const uWastelandLODBudgetAdjustment;
		static Setting* const uWaterCount;
		static Setting* const uWaterCountInterior;
		static Setting* const uWaterMemory;
		static Setting* const uWaterMemoryInterior;

		static Setting* const fMaxMsUsagePerFrame;
		static Setting* const fMsActiveRefCount;
		static Setting* const fMsActorRefCount;
		static Setting* const fMsAnimatedObjectsCount;
		static Setting* const fMsDecalCount;
		static Setting* const fMsEmittersCount;
		static Setting* const fMsGeometryCount;
		static Setting* const fMsHavokTriCount;
		static Setting* const fMsLightCount;
		static Setting* const fMsLightExcessGeometry;
		static Setting* const fMsParticlesCount;
		static Setting* const fMsRefCount;
		static Setting* const fMsTriangleCount;
		static Setting* const fMsWaterCount;
	};

	struct CameraPath {
		static Setting* const iFPS;
		static Setting* const iTake;

		static Setting* const sDirectoryName;
		static Setting* const sNif;
	};

	struct Combat {
		static Setting* const bAimSights;
		static Setting* const bDebugCombatArea;
		static Setting* const bDebugCombatAttackerText;
		static Setting* const bDebugCombatCoverReservations;
		static Setting* const bDebugCombatCoverReservationsText;
		static Setting* const bDebugCombatCoverSearch2;
		static Setting* const bDebugCombatCoverSearch;
		static Setting* const bDebugCombatCoverSearchText;
		static Setting* const bDebugCombatDetectionEvents;
		static Setting* const bDebugCombatGroupClusters;
		static Setting* const bDebugCombatGroups2;
		static Setting* const bDebugCombatGroups;
		static Setting* const bDebugCombatGuardRadius;
		static Setting* const bDebugCombatProjectileLOS;
		static Setting* const bDebugCombatSearch;
		static Setting* const bDebugCombatTargets;
		static Setting* const bDebugCombatTextColorDark;
		static Setting* const bDebugCombatThreats;
		static Setting* const bDebugCombatUnreachableLocations;
		static Setting* const bDisableCombatDialogue;
		static Setting* const bDisableCombatGroupStrategies;
		static Setting* const bDisableNPCAttacks;
		static Setting* const bDismemberOneLimb;
		static Setting* const bEncounterZoneTargetRestrict;
		static Setting* const bForceNPCsUseAmmo;
		static Setting* const bIronSightsZoomEnable;
		static Setting* const bLaserSights;
		static Setting* const bPlayHitLocationIdles;
		static Setting* const bPlayStaggers;
		static Setting* const bProjectileDebug;
		static Setting* const bVATSProjectileDebug;
		static Setting* const bVatsAlwaysHit;

		static Setting* const iMaxHiPerfCombatCount;
		static Setting* const iMaxHiPerfNPCTargetCount;
		static Setting* const iMaxHiPerfPCTargetCount;
		static Setting* const iShowHitVector;

		static Setting* const fAimChaseLookingMult;
		static Setting* const fAimDownDegrees;
		static Setting* const fAimUpDegrees;
		static Setting* const fDebugCombatProjectileLOSTime;
		static Setting* const fDebugCombatTextSize;
		static Setting* const fHiPerfNPCTargetLOSTimer;
		static Setting* const fHiPerfPCTargetLOSTimer;
		static Setting* const fHitVectorDelay;
		static Setting* const fIronSightsZoomDefault;
		static Setting* const fLowPerfNPCTargetLOSTimer;
		static Setting* const fLowPerfPCTargetLOSTimer;
		static Setting* const fMinBloodDamage;
		static Setting* const fProjectileDebugDuration;
	};

	struct CopyProtectionStrings {
		static Setting* const sCopyProtectionMessage2;
		static Setting* const sCopyProtectionMessage;
		static Setting* const sCopyProtectionTitle2;
		static Setting* const sCopyProtectionTitle;
	};

	struct Controls {
		static Setting* const bAlwaysRunByDefault;
		static Setting* const bBackgroundKeyboard;
		static Setting* const bBackgroundMouse;
		static Setting* const bUseJoystick;

		static Setting* const iJoystickLookLeftRight;
		static Setting* const iJoystickLookUpDown;
		static Setting* const iJoystickMoveFrontBack;
		static Setting* const iJoystickMoveLeftRight;
		static Setting* const iLanguage;
		static Setting* const iXenonHorizLookAccel;
		static Setting* const iXenonMenuStickDeadZone;
		static Setting* const iXenonVertLookAccel;

		static Setting* const fAnalogMaxRunZonePercent;
		static Setting* const fAnalogRunZonePercent;
		static Setting* const fForegroundMouseAccelBase;
		static Setting* const fForegroundMouseAccelTop;
		static Setting* const fForegroundMouseBase;
		static Setting* const fForegroundMouseMult;
		static Setting* const fForwardBias;
		static Setting* const fJoystickLookLRMult;
		static Setting* const fJoystickLookUDMult;
		static Setting* const fJoystickMoveFBMult;
		static Setting* const fJoystickMoveLRMult;
		static Setting* const fMaxAnalogRunSpeed;
		static Setting* const fMaxAnalogWalkSpeed;
		static Setting* const fMinAnalogRunSpeed;
		static Setting* const fMinAnalogWalkSpeed;
		static Setting* const fPlayerSettingacterTurnMult;
		static Setting* const fUFOCamSpeedMult;
		static Setting* const fXenonMenuDpadRepeatSpeed;
		static Setting* const fXenonMenuMouseXYMult;
		static Setting* const fXenonMenuStickSpeed;
		static Setting* const fXenonMenuStickSpeedMaxMod;
		static Setting* const fXenonMenuStickSpeedPlayerRotMod;
		static Setting* const fXenonMinLookSpeed;
	};
	
	struct Decals {
		static Setting* const bDebugDecals;
		static Setting* const bDecalMultithreaded;
		static Setting* const bDecalOcclusionQuery;
		static Setting* const bDecals;
		static Setting* const bProfileDecals;
		static Setting* const bSkinnedDecals;

		static Setting* const uMaxSkinDecalPerActor;
		static Setting* const uMaxSkinDecals;
	};
	
	struct Debug {
		static Setting* const bDebugFaceGenCriticalSection;
		static Setting* const bDebugFaceGenMultithreading;
		static Setting* const bDebugSaveBuffer;
	};

	struct Display {
		static Setting* const bActorSelfShadowing;
		static Setting* const bAllow20HairShader;
		static Setting* const bAllow30Shaders;
		static Setting* const bAllowPartialPrecision;
		static Setting* const bAllowScreenShot;
		static Setting* const bAutoViewDistance;
		static Setting* const bDecalsOnSkinnedGeometry;
		static Setting* const bDo30VFog;
		static Setting* const bDoActorShadows;
		static Setting* const bDoAmbientPass;
		static Setting* const bDoCanopyShadowPass;
		static Setting* const bDoDiffusePass;
		static Setting* const bDoSpecularPass;
		static Setting* const bDoStaticAndArchShadows;
		static Setting* const bDoTallGrassEffect;
		static Setting* const bDoTestHDR;
		static Setting* const bDoTexturePass;
		static Setting* const bDynamicWindowReflections;
		static Setting* const bEquippedTorchesCastShadows;
		static Setting* const bForce1XShaders;
		static Setting* const bForceMultiPass;
		static Setting* const bForcePow2Textures;
		static Setting* const bIgnoreResolutionCheck;
		static Setting* const bImageSpaceEffects;
		static Setting* const bLODNoiseAniso;
		static Setting* const bMTRendering;
		static Setting* const bReportBadTangentSpace;
		static Setting* const bShadowsOnGrass;
		static Setting* const bShowMenuTextureUse;
		static Setting* const bStaticMenuBackground;
		static Setting* const bUseFakeFullScreenMotionBlur;
		static Setting* const bUseRefractionShader;
		static Setting* const bUseResolvableDepth;
		static Setting* const bUseShaders;
		static Setting* const bUseSunbeams;

		static Setting* const iAutoViewHiFrameRate;
		static Setting* const iAutoViewLowFrameRate;
		static Setting* const iAutoViewMinDistance;
		static Setting* const iDebugTextLeftRightOffset;
		static Setting* const iDebugTextTopBottomOffset;
		static Setting* const iLocationX;
		static Setting* const iLocationY;
		static Setting* const iNPatchNOrder;
		static Setting* const iNPatchPOrder;
		static Setting* const iNPatches;
		static Setting* const iPresentInterval;

		static Setting* const uVideoDeviceIdentifierPart1;
		static Setting* const uVideoDeviceIdentifierPart2;
		static Setting* const uVideoDeviceIdentifierPart3;
		static Setting* const uVideoDeviceIdentifierPart4;

		static Setting* const sDebugText;
		static Setting* const sScreenShotBaseName;

		static Setting* const fDecalLOD0;
		static Setting* const fDecalLifetime;
		static Setting* const fDefault1stPersonFOV;
		static Setting* const fDefaultFOV;
		static Setting* const fDefaultWorldFOV;
		static Setting* const fEnvMapLOD1;
		static Setting* const fEnvMapLOD2;
		static Setting* const fEyeEnvMapLOD1;
		static Setting* const fEyeEnvMapLOD2;
		static Setting* const fGammaMax;
		static Setting* const fGammaMin;
		static Setting* const fLODNoiseMipBias;
		static Setting* const fLandLOFadeSeconds;
		static Setting* const fLightLODDefaultStartFade;
		static Setting* const fLightLODMaxStartFade;
		static Setting* const fLightLODMinStartFade;
		static Setting* const fLightLODRange;
		static Setting* const fNearDistance;
		static Setting* const fNoLODFarDistanceMax;
		static Setting* const fNoLODFarDistanceMin;
		static Setting* const fNoLODFarDistancePct;
		static Setting* const fPipboy1stPersonFOV;
		static Setting* const fScopeScissorAmount;
		static Setting* const fShadowFadeTime;
		static Setting* const fShadowLODDefaultStartFade;
		static Setting* const fShadowLODMaxStartFade;
		static Setting* const fShadowLODMinStartFade;
		static Setting* const fShadowLODRange;
		static Setting* const fSkinnedDecalLOD0;
		static Setting* const fSkinnedDecalLOD1;
		static Setting* const fSkinnedDecalLOD2;
		static Setting* const fSpecularLODDefaultStartFade;
		static Setting* const fSpecularLODMaxStartFade;
		static Setting* const fSpecularLODMinStartFade;
		static Setting* const fSpecularLODRange;
	};

	struct DistantLOD {
		static Setting* const iDistantLODGroupWidth;
	};

	struct FootIK {
		static Setting* const bFootPlacementOn;
		static Setting* const bRigidBodyController;

		static Setting* const iNumFramesFootEaseOut;

		static Setting* const fAnkleOffset;
		static Setting* const fControllerTetherLen;
		static Setting* const fFootPlantedGain;
		static Setting* const fFootRaisedGain;
		static Setting* const fGroundAscendingGain;
		static Setting* const fGroundDescendingGain;
		static Setting* const fMaxFootCastMilliSec;
		static Setting* const fMaxStepVertError;
		static Setting* const fOnOffGain;
		static Setting* const fOriginalGroundHeightMS;
		static Setting* const fPelvisOffsetDamping;
		static Setting* const fPelvisUpDownBias;
		static Setting* const fRagdollFeedback;
		static Setting* const fVertErrorGain;
	};

	struct Fonts {
		static Setting* const sFontFile_1;
		static Setting* const sFontFile_2;
		static Setting* const sFontFile_3;
		static Setting* const sFontFile_4;
		static Setting* const sFontFile_5;
		static Setting* const sFontFile_6;
		static Setting* const sFontFile_7;
		static Setting* const sFontFile_8;
	};

	struct GamePlay {
		static Setting* const bAllowHavokGrabTheLiving;
		static Setting* const bEssentialTakeNoDamage;
		static Setting* const bHealthBarShowing;
		static Setting* const bInstantLevelUp;
		static Setting* const bSetDemigodMode;
		static Setting* const bShowChallengeUpdates;
		static Setting* const bTrackProgress;

		static Setting* const iActorsDismemberedPerFrame;
		static Setting* const iDetectionPicks;

		static Setting* const sTrackProgressPath;

		static Setting* const fHealthBarEmittanceFadeTime;
		static Setting* const fHealthBarEmittanceTime;
		static Setting* const fHealthBarFadeOutSpeed;
		static Setting* const fHealthBarHeight;
		static Setting* const fHealthBarSpeed;
		static Setting* const fHealthBarWidth;
	};

	struct General {
		static Setting* const bActivateAllQuestScripts;
		static Setting* const bActorLookWithHavok;
		static Setting* const bAlwaysActive;
		static Setting* const bAnimateDoorPhysics;
		static Setting* const bBorderRegionsEnabled;
		static Setting* const bCRTMemoryChecks;
		static Setting* const bChangeTimeMultSlowly;
		static Setting* const bCheckCellOffsetsOnInit;
		static Setting* const bCheckPurgedTextureList;
		static Setting* const bCreateMapsEnable;
		static Setting* const bCreateShaderPackage;
		static Setting* const bDebugSpectatorThreats;
		static Setting* const bDefaultCOCPlacement;
		static Setting* const bDisableAllGore;
		static Setting* const bDisableAutoVanityMode;
		static Setting* const bDisableDuplicateReferenceCheck;
		static Setting* const bDisplayBoundingVolumes;
		static Setting* const bDrawSpellContact;
		static Setting* const bEnableBoundingVolumeOcclusion;
		static Setting* const bExternalLODDataFiles;
		static Setting* const bFaceGenTexturing;
		static Setting* const bFaceMipMaps;
		static Setting* const bFadeInScreenShot;
		static Setting* const bFixAIPackagesOnLoad;
		static Setting* const bFixFaceNormals;
		static Setting* const bKeepPluginWhenMerging;
		static Setting* const bLoadFaceGenHeadEGTFiles;
		static Setting* const bPreCullActors;
		static Setting* const bPreemptivelyUnloadCells;
		static Setting* const bPreloadIntroSequence;
		static Setting* const bQueueWarnings;
		static Setting* const bRenderLocalMapContinually;
		static Setting* const bRunActorMovementDuringRendering;
		static Setting* const bRunDetectionDuringRendering;
		static Setting* const bRunMiddleLowLevelProcess;
		static Setting* const bRunVTuneTest;
		static Setting* const bShowCheckMemoryOutput;
		static Setting* const bShowGunTarget;
		static Setting* const bShowLoadingAreaMessage;
		static Setting* const bTaskletActorAnimMovementUpdates;
		static Setting* const bTaskletActorHavokSync;
		static Setting* const bTaskletActorSceneGraphUpdates;
		static Setting* const bTaskletCellTransformsUpdate;
		static Setting* const bTaskletTempEffectsUpdate;
		static Setting* const bTintMipMaps;
		static Setting* const bTrackAllDeaths;
		static Setting* const bUseEyeEnvMapping;
		static Setting* const bUseFaceGenHeads;
		static Setting* const bUseHardDriveCache;
		static Setting* const bUseMovementBlockedPackage;
		static Setting* const bUseMultibounds;
		static Setting* const bUseMyGamesDirectory;
		static Setting* const bUseOptimizedTextureLoading;
		static Setting* const bUseThreadedAI;
		static Setting* const bUseThreadedMorpher;
		static Setting* const bUseThreadedParticleSystem;
		static Setting* const bUseThreadedTempEffects;
		static Setting* const bWarnOnMissingFileEntry;

		static Setting* const iAIThread1HWThread;
		static Setting* const iAIThread2HWThread;
		static Setting* const iFPSClamp;
		static Setting* const iHWThread1;
		static Setting* const iHWThread2;
		static Setting* const iHWThread3;
		static Setting* const iHWThread4;
		static Setting* const iHWThread5;
		static Setting* const iHWThread6;
		static Setting* const iHoursToSleep;
		static Setting* const iIntroSequencePriority;
		static Setting* const iNumBitsForFullySeen;
		static Setting* const iNumHWThreads;
		static Setting* const iPreloadSizeLimit;
		static Setting* const iRenderingThread1HWThread;
		static Setting* const iRenderingThread2HWThread;

		static Setting* const uExteriorCellBuffer;
		static Setting* const uGridsToLoad;
		static Setting* const uInteriorCellBuffer;
		static Setting* const uiEGTClampSize;
		static Setting* const uiFaceGenMaxEGMDataSize;
		static Setting* const uiFaceGenMaxEGTDataSize;

		static Setting* const sSettingGenQuest;
		static Setting* const sEssentialFileCacheList;
		static Setting* const sIntroMovie;
		static Setting* const sIntroSequence;
		static Setting* const sLanguage;
		static Setting* const sLocalMasterPath;
		static Setting* const sLocalSavePath;
		static Setting* const sMainMenuMovieIntro;
		static Setting* const sStartingCell;
		static Setting* const sStartingCellX;
		static Setting* const sStartingCellY;
		static Setting* const sStartingWorld;
		static Setting* const sTestFile10;
		static Setting* const sTestFile1;
		static Setting* const sTestFile2;
		static Setting* const sTestFile3;
		static Setting* const sTestFile4;
		static Setting* const sTestFile5;
		static Setting* const sTestFile6;
		static Setting* const sTestFile7;
		static Setting* const sTestFile8;
		static Setting* const sTestFile9;
		static Setting* const sUnessentialFileCacheList;

		static Setting* const fAnimationDefaultBlend;
		static Setting* const fAnimationMult;
		static Setting* const fDegradeTexturesDistance;
		static Setting* const fLODActorAvoidanceDistance;
		static Setting* const fUpgradeTexturesDistance;
		static Setting* const fZoom3rdPersonSnapDist;
	};

	struct GeneralWarnings {
		static Setting* const sGeneralMasterMismatchWarning;
		static Setting* const sMasterMismatchWarning;
	};

	struct Grass {
		static Setting* const bDrawShaderGrass;
		static Setting* const bGrassPointLighting;

		static Setting* const iGrassDensityEvalSize;
		static Setting* const iMaxGrassTypesPerTexure;
		static Setting* const iMinGrassSize;

		static Setting* const fGrassDefaultStartFadeDistance;
		static Setting* const fGrassFadeRange;
		static Setting* const fGrassMaxStartFadeDistance;
		static Setting* const fGrassMinStartFadeDistance;
		static Setting* const fGrassWindMagnitudeMax;
		static Setting* const fGrassWindMagnitudeMin;
		static Setting* const fTexturePctThreshold;
		static Setting* const fWaveOffsetRange;
	};

	struct GrabIK {
		static Setting* const fDriveGain;
	};

	struct GethitShader {
		static Setting* const fBlockedTexOffset;
		static Setting* const fBlurAmmount;
		static Setting* const fHitTexOffset;
	};

	struct HAVOK {
		static Setting* const bAddBipedWhenKeyframed;
		static Setting* const bAutoWaterUsesHavokShapes;
		static Setting* const bDisablePlayerCollision;
		static Setting* const bFindContactPointsOnAdd;
		static Setting* const bHavokDebug;
		static Setting* const bPreventHavokAddAll;
		static Setting* const bPreventHavokAddClutter;
		static Setting* const bTreeTops;
		static Setting* const bWONameSync;

		static Setting* const iEntityBatchRemoveRate;
		static Setting* const iMinNumSubSteps;
		static Setting* const iSimType;
		static Setting* const iUpdateType;
		static Setting* const iHavokSkipFrameCountTEST;

		static Setting* const fCameraCasterFadeSittingRadius;
		static Setting* const fCameraCasterPlayerSize;
		static Setting* const fCameraCasterSize;
		static Setting* const fSettingControllerWarpDistSqr;
		static Setting* const fChaseDeltaMult;
		static Setting* const fJumpAnimDelay;
		static Setting* const fMaxPickTime;
		static Setting* const fMaxPickTimeDebug;
		static Setting* const fMaxPickTimeDebugVATS;
		static Setting* const fMaxPickTimeVATS;
		static Setting* const fMaxTime;
		static Setting* const fMoveLimitMass;
		static Setting* const fOD;
		static Setting* const fQuadrupedPitchMult;
		static Setting* const fRF;
		static Setting* const fSD;
		static Setting* const fSE;
		static Setting* const fTimePerSubStep;
	};

	struct Hacking {
		static Setting* const fHackingMinSkillAverage;
		static Setting* const fHackingMinSkillEasy;
		static Setting* const fHackingMinSkillHard;
		static Setting* const fHackingMinSkillVeryEasy;
		static Setting* const fHackingMinSkillVeryHard;
	};

	struct HeadTracking {
		static Setting* const bDisableHeadTracking;

		static Setting* const iUpdateActorsPerFrame;

		static Setting* const fUpdateDelayNewTargetSecondsMax;
		static Setting* const fUpdateDelayNewTargetSecondsMin;
		static Setting* const fUpdateDelaySecondsMax;
		static Setting* const fUpdateDelaySecondsMin;
	};

	struct Imagespace {
		static Setting* const bDoMotionBlur;
		static Setting* const bDoRadialBlur;

		static Setting* const fRenderDepthMaxDepth;
	};

	struct InterfaceFX {
		static Setting* const bEnableMenuRenderDebugMode;
		static Setting* const bUseImageSpaceMenuFX;
		static Setting* const bUseOptimizedMenuRendering;

		static Setting* const iDistortMaxInterval;

		static Setting* const sScanlineTexture;

		static Setting* const fBlurIntensityHUD;
		static Setting* const fBlurIntensityMenus;
		static Setting* const fBlurRadiusHUD;
		static Setting* const fBlurRadiusMenus;
		static Setting* const fDefaultBlurIntensity;
		static Setting* const fDefaultBlurRadius;
		static Setting* const fDefaultBurstDuration;
		static Setting* const fDefaultBurstIntensity;
		static Setting* const fDefaultScanlineFrequency;
		static Setting* const fDefaultShudderDuration;
		static Setting* const fDefaultShudderFrequency;
		static Setting* const fDefaultShudderIntensity;
		static Setting* const fDefaultVertHoldDuration;
		static Setting* const fDefaultVertHoldSpeed;
		static Setting* const fDistortDuration;
		static Setting* const fDistortHorizontalScale;
		static Setting* const fDistortVerticalScale;
		static Setting* const fHUDShudderDefaultDuration;
		static Setting* const fHUDShudderDefaultFrequencyX;
		static Setting* const fHUDShudderDefaultFrequencyY;
		static Setting* const fHUDShudderDefaultIntensity;
		static Setting* const fMenuPackerBufferOverflowZone;
		static Setting* const fMenuPackerBufferSize;
		static Setting* const fMiniBurstDuration;
		static Setting* const fMiniBurstIntensity;
		static Setting* const fPulseBrightenIntensity;
		static Setting* const fPulseRadiusIntensity;
		static Setting* const fPulseRate;
		static Setting* const fScanlineFrequencyHUD;
		static Setting* const fScanlineFrequencyMenus;
		static Setting* const fScreenLightBaseIntensity;
		static Setting* const fScreenLightBurstModifier;
		static Setting* const fScreenLightPulseModifier;
		static Setting* const fScreenLightRadius;
		static Setting* const fScreenLightVertHoldRate;
		static Setting* const fShudderChance;
		static Setting* const fVertHoldChance;
	};

	struct Interface {
		static Setting* const bActivatePickUseGamebryoPick;
		static Setting* const bAllowConsole;
		static Setting* const bHideUnavailablePerks;
		static Setting* const bUseFuzzyPicking;

		static Setting* const iMaxViewCasterPicksFuzzy;
		static Setting* const iMaxViewCasterPicksGamebryo;
		static Setting* const iMaxViewCasterPicksHavok;
		static Setting* const iSafeZoneX;
		static Setting* const iSafeZoneXWide;
		static Setting* const iSafeZoneY;
		static Setting* const iSafeZoneYWide;

		static Setting* const fActivatePickSphereRadius;
		static Setting* const fDlgFocus;
		static Setting* const fDlgHeadingDegStart;
		static Setting* const fDlgHeadingDegStop;
		static Setting* const fDlgLookAdj;
		static Setting* const fDlgLookDegStart;
		static Setting* const fDlgLookDegStop;
		static Setting* const fDlgLookMult;
		static Setting* const fHUDShakeMult;
		static Setting* const fInterfaceTintB;
		static Setting* const fInterfaceTintG;
		static Setting* const fInterfaceTintR;
		static Setting* const fKeyRepeatInterval;
		static Setting* const fKeyRepeatTime;
		static Setting* const fMenuBGBlurRadius;
		static Setting* const fMenuBackgroundOpacity;
		static Setting* const fMenuModeAnimBlend;
		static Setting* const fMenuPlayerLightAmbientBlue;
		static Setting* const fMenuPlayerLightAmbientGreen;
		static Setting* const fMenuPlayerLightAmbientRed;
		static Setting* const fMenuPlayerLightDiffuseBlue;
		static Setting* const fMenuPlayerLightDiffuseGreen;
		static Setting* const fMenuPlayerLightDiffuseRed;
		static Setting* const fPopUpBackgroundOpacity;
		static Setting* const fRSMFaceSliderDefaultMax;
		static Setting* const fRSMFaceSliderDefaultMin;
		static Setting* const fRSMStartingZoom;
	};

	struct LOD {
		static Setting* const bDisplayLODLand;
		static Setting* const bUseFaceGenLOD;

		static Setting* const iFadeNodeMinNearDistance;

		static Setting* const fActorLODDefault;
		static Setting* const fActorLODMax;
		static Setting* const fActorLODMin;
		static Setting* const fDistanceMultiplier;
		static Setting* const fFadeInThreshold;
		static Setting* const fFadeInTime;
		static Setting* const fFadeOutThreshold;
		static Setting* const fFadeOutTime;
		static Setting* const fItemLODDefault;
		static Setting* const fItemLODMax;
		static Setting* const fItemLODMin;
		static Setting* const fLODBoundRadiusMult;
		static Setting* const fLODFadeOutActorMultCity;
		static Setting* const fLODFadeOutActorMultComplex;
		static Setting* const fLODFadeOutActorMultInterior;
		static Setting* const fLODFadeOutItemMultCity;
		static Setting* const fLODFadeOutItemMultComplex;
		static Setting* const fLODFadeOutItemMultInterior;
		static Setting* const fLODFadeOutObjectMultCity;
		static Setting* const fLODFadeOutObjectMultComplex;
		static Setting* const fLODFadeOutObjectMultInterior;
		static Setting* const fLODFadeOutPercent;
		static Setting* const fLODLandDropAmount;
		static Setting* const fLODLandVerticalBias;
		static Setting* const fLODMultTrees;
		static Setting* const fLodDistance;
		static Setting* const fObjectLODDefault;
		static Setting* const fObjectLODMax;
		static Setting* const fObjectLODMin;
		static Setting* const fTalkingDistance;
	};

	struct Landscape {
		static Setting* const bCurrentCellOnly;
		static Setting* const bPreventSafetyCheck;

		static Setting* const iLandBorder1B;
		static Setting* const iLandBorder1G;
		static Setting* const iLandBorder1R;
		static Setting* const iLandBorder2B;
		static Setting* const iLandBorder2G;
		static Setting* const iLandBorder2R;

		static Setting* const sDefaultLandDiffuseTexture;
		static Setting* const sDefaultLandNormalTexture;

		static Setting* const fLandFriction;
		static Setting* const fLandTextureTilingMult;
	};

	struct LANGUAGE {
		static Setting* const sDPad;
		static Setting* const sFailureMessage;
		static Setting* const sSysUtil_AutoSaveWarning;
		static Setting* const sSysUtil_DirtyDisc;
		static Setting* const sSysUtil_DiscEject;
		static Setting* const sSysUtil_GameDataCorrupt;
		static Setting* const sSysUtil_GameDataInsufficientSpace;
		static Setting* const sSysUtil_Retry;
		static Setting* const sSysUtil_SaveDataCreateNew;
		static Setting* const sSysUtil_SaveDataInsufficientSpace;
		static Setting* const sThumbstick;
	};

	struct Loading {
		static Setting* const iMaxScreens;
		static Setting* const iMaxScreens_MainMenu;
		static Setting* const iNumLocationSpecificScreens;

		static Setting* const sInitialSound;
		static Setting* const sMainMenuBackground;
		static Setting* const sTitleMusic;
		static Setting* const sWelcomeScreen1;
		static Setting* const sWelcomeScreen2;
		static Setting* const sWelcomeScreen3;
		static Setting* const sWelcomeScreen4;

		static Setting* const fLoadingBkgdUpdateInterval;
		static Setting* const fLoadingInitUpdateInterval;
		static Setting* const fLoadingTextUpdateInterval;
		static Setting* const fMainMenuBkgdUpdateInterval;
	};

	struct LookIK {
		static Setting* const fAngleMax;
		static Setting* const fAngleMaxEase;
		static Setting* const fEaseAngleShutOff;
		static Setting* const fMaxTrackingDist;
		static Setting* const fMinTrackingDist;
	};

	struct MAIN {
		static Setting* const fQuestScriptDelayTime;
	};

	struct MESSAGES {
		static Setting* const bAllowYesToAll;
		static Setting* const bBlockMessageBoxes;
		static Setting* const bSkipInitializationFlows;
		static Setting* const bSkipProgramFlows;
		static Setting* const bUseWindowsMessageBox;

		static Setting* const iFileLogging;
	};

	struct Menu {
		static Setting* const iConsoleFont;
		static Setting* const iConsoleHistorySize;
		static Setting* const iConsoleLineSpacing;
		static Setting* const iConsoleTextXPos;
		static Setting* const iConsoleTextYPos;
		static Setting* const iConsoleVisibleLines;
		static Setting* const iDebugTextFont;

		static Setting* const fCreditsScrollSpeed;

		static Setting* const rDebugTextColor;
	};

	struct NavMeshGeneration {
		static Setting* const bGlobalNavMeshCheck;
	};

	struct Online {
		static Setting* const bXenonLoadDownloadedContent;

		static Setting* const uXenonPresenceUpdateInterval;
	};

	struct Pathfinding {
		static Setting* const bBackgroundNavmeshUpdate;
		static Setting* const bBackgroundPathing;
		static Setting* const bCreateDebugInfo;
		static Setting* const bCutDoors;
		static Setting* const bDrawPathBounds;
		static Setting* const bRebuildPathIfSmootherFailed;
		static Setting* const bSelectedPathDrawAvoidNodes;
		static Setting* const bUseActorAvoidance;
		static Setting* const bUseAlternateSmoothingForPrime;
		static Setting* const bUseFartherCheckForAvoidance;
		static Setting* const bUseObstacleAvoidance;
		static Setting* const bUseOldPathSmoothing;
		static Setting* const bUsePathSmoothing;
		static Setting* const bUseRayCasts;
		static Setting* const bUseStraightLineCheckFirst;

		static Setting* const fAICombatTurnSpeedScale;
		static Setting* const fAITurnSpeedScale;
		static Setting* const fAvoidanceAvoidAllRadius;
		static Setting* const fAvoidanceConeAngle;
		static Setting* const fAvoidanceDefaultWaitTime;
		static Setting* const fAvoidanceDetectionTime;
		static Setting* const fAvoidanceIgnoreMinTime;
		static Setting* const fAvoidanceIgnoreTime;
		static Setting* const fAvoidanceMinWaitTime;
		static Setting* const fAvoidanceTimeCheck;
		static Setting* const fAvoidanceWiderConeAngle;
		static Setting* const fCreatureCombatTurnSpeedScale;
		static Setting* const fCreatureTurnSpeedScale;
		static Setting* const fObstacleUpdateDeltaWhenMoving;
		static Setting* const fObstacleUpdateDeltaWhenUnknown;
		static Setting* const fPOVSmootherAvoidNodeCost;
		static Setting* const fRepathingWaitDistance;
		static Setting* const fRotationSpeedIncrease;
		static Setting* const fRunningWiderConeAngle;
	};

	struct Pathing {
		static Setting* const fFindClosestEdgesRadius;
		static Setting* const fINIDetectDoorsForPathingTime;
	};

	struct Pipboy {
		static Setting* const bEnableFlickerPipboy;
		static Setting* const bUsePipboyMode;

		static Setting* const fBlurIntensityPipboy;
		static Setting* const fBlurRadiusPipboy;
		static Setting* const fLightEffectFadeDuration;
		static Setting* const fLightEffectLightFadeDuration;
		static Setting* const fScanlineFrequencyPipboy;
		static Setting* const fScrollKnobIncrement;
		static Setting* const fScrollKnobRate;
		static Setting* const fTabKnobMaxPosition;
		static Setting* const fTabKnobMinPosition;
		static Setting* const fTabKnobMoveRate;
	};

	struct RagdollAnim {
		static Setting* const bFootIK;
		static Setting* const bGrabIK;
		static Setting* const bLookIK;
		static Setting* const bPoseMatching;
		static Setting* const bRagdollAnim;
		static Setting* const bRagdollFeedback;

		static Setting* const fAccelerationGain;
		static Setting* const fCameraDist;
		static Setting* const fDesiredVel;
		static Setting* const fDetectionUpdateTimeSec;
		static Setting* const fHierarchyGain;
		static Setting* const fImpulseLimit;
		static Setting* const fPositionGain;
		static Setting* const fPositionMaxAngularVelocity;
		static Setting* const fPositionMaxLinearVelocity;
		static Setting* const fSnapGain;
		static Setting* const fSnapMaxAngularDistance;
		static Setting* const fSnapMaxAngularVelocity;
		static Setting* const fSnapMaxLinearDistance;
		static Setting* const fSnapMaxLinearVelocity;
		static Setting* const fVelocityDamping;
		static Setting* const fVelocityGain;
	};

	struct RagdollFeedback {
		static Setting* const uiFeedbackTimeout;
	};

	struct RenderedMenus {
		static Setting* const fRaceSexMenuDistortDuration;
	};

	struct RenderedTerminal {
		static Setting* const bUseRenderedTerminals;

		static Setting* const fRaceSexMenuHPos;
		static Setting* const fRaceSexMenuScale;
		static Setting* const fRaceSexMenuVPos;
		static Setting* const fRaceSexMenuZoom;
		static Setting* const fRenderedTerminalFOV;
		static Setting* const fRenderedTerminalHPos;
		static Setting* const fRenderedTerminalScanlineScale;
		static Setting* const fRenderedTerminalVPos;
		static Setting* const fRenderedTerminalZoom;
		static Setting* const fScreenLightBaseIntensity;
		static Setting* const fScreenLightColorB;
		static Setting* const fScreenLightColorG;
		static Setting* const fScreenLightColorR;
		static Setting* const fScreenLightRadius;
	};

	struct SaveGame {
		static Setting* const bAllowProfileTransfer;
		static Setting* const bAllowScriptedAutosave;
		static Setting* const bAllowScriptedForceSave;
		static Setting* const bCopySaveGameToHostOrMemStick;
		static Setting* const bDisplayMissingContentDialogue;
		static Setting* const bOutputSaveGameScreenshot;
		static Setting* const bUseSaveGameHistory;

		static Setting* const iSaveGameBackupCount;

		static Setting* const sSaveGameSafeMarkerID;
	};

	struct ScreenSplatter {
		static Setting* const bBloodSplatterEnabled;
		static Setting* const bCustomSplatterEnabled;
	};

	struct SpeedTree {
		static Setting* const bEnableTrees;
		static Setting* const bForceFullLOD;

		static Setting* const iCanopyShadowScale;

		static Setting* const fCanopyShadowGrassMult;
		static Setting* const fLODTreeMipMapLODBias;
		static Setting* const fLocalTreeMipMapLODBias;
		static Setting* const fTreeForceBranchDimming;
		static Setting* const fTreeForceCS;
		static Setting* const fTreeForceLLA;
		static Setting* const fTreeForceLeafDimming;
		static Setting* const fTreeForceMaxBudAngle;
		static Setting* const fTreeForceMinBudAngle;
		static Setting* const fTreeLODExponent;
	};

	struct Surgery {
		static Setting* const fSurgeryPlayerDefaultHPos3D;
		static Setting* const fSurgeryPlayerDefaultScale3D;
		static Setting* const fSurgeryPlayerDefaultVPos3D;
		static Setting* const fSurgeryPlayerZoom3D;
		static Setting* const fSurgerySkinHPos3D;
		static Setting* const fSurgerySkinScale3D;
		static Setting* const fSurgerySkinVPos3D;
		static Setting* const fSurgerySkinZoom3D;
	};

	struct TerrainManager {
		static Setting* const bKeepLowDetailTerrain;
		static Setting* const bUseDistantObjectBlocks;
		static Setting* const bUseDistantTrees;
		static Setting* const bUseNewTerrainSystem;

		static Setting* const uDistantTreeBlockCacheSizePerCell;
		static Setting* const uTerrainTextureFadeTime;

		static Setting* const fDefaultBlockLoadDistanceLow;
		static Setting* const fDefaultTreeLoadDistance;
		static Setting* const fDetailTextureScale;
		static Setting* const fHighBlockLoadDistanceLow;
		static Setting* const fHighTreeLoadDistance;
		static Setting* const fLowBlockLoadDistanceLow;
		static Setting* const fLowTreeLoadDistance;
		static Setting* const fMorphEndDistanceMult;
		static Setting* const fMorphStartDistanceMult;
	};

	struct TestAllCells {
		static Setting* const bFileCheckModelCollision;
		static Setting* const bFileControllerOnRoot;
		static Setting* const bFileGoneMessage;
		static Setting* const bFileNeededMessage;
		static Setting* const bFileShowIcons;
		static Setting* const bFileShowTextures;
		static Setting* const bFileSkipIconChecks;
		static Setting* const bFileSkipModelChecks;
		static Setting* const bFileTestLoad;
		static Setting* const bFileUnusedObject;
	};

	struct VATS {
		static Setting* const bVATSSmartCameraCheckDebug;

		static Setting* const iDistortMaxInterval;

		static Setting* const sScanlineTexture;

		static Setting* const fBlurIntensity;
		static Setting* const fBlurRadius;
		static Setting* const fBurstDuration;
		static Setting* const fBurstIntensity;
		static Setting* const fDistortDuration;
		static Setting* const fDistortHorizontalScale;
		static Setting* const fDistortVerticalScale;
		static Setting* const fPulseIntensity;
		static Setting* const fPulseRadius;
		static Setting* const fPulseRate;
		static Setting* const fScanModeDuration;
		static Setting* const fScanModeScanlineFrequency;
		static Setting* const fScanModeVerticalScale;
		static Setting* const fScanlineFrequency;
		static Setting* const fVATSColorB;
		static Setting* const fVATSColorG;
		static Setting* const fVATSColorR;
		static Setting* const fVATSLightAngle;
		static Setting* const fVATSLightDistance;
		static Setting* const fVATSLightElevation;
		static Setting* const fVATSLightLevelMax;
		static Setting* const fVATSLightLevelMin;
		static Setting* const fVATSTargetPulseRate;
		static Setting* const fVatsLightColorB;
		static Setting* const fVatsLightColorG;
		static Setting* const fVatsLightColorR;
	};

	struct Voice {
		static Setting* const sFileTypeGame;
		static Setting* const sFileTypeLTF;
		static Setting* const sFileTypeLip;
		static Setting* const sFileTypeSource;
	};

	struct Water {
		static Setting* const bForceHighDetailLandReflections;
		static Setting* const bForceLowDetailReflections;
		static Setting* const bReflectExplosions;
		static Setting* const bUseBulletWaterDisplacements;
		static Setting* const bUsePerWorldSpaceWaterNoise;
		static Setting* const bUseWater;
		static Setting* const bUseWaterHiRes;
		static Setting* const bUseWaterLOD;
		static Setting* const bUseWaterShader;

		static Setting* const iWaterNoiseResolution;

		static Setting* const uMaxExteriorWaterReflections;
		static Setting* const uMaxInteriorWaterReflections;
		static Setting* const uNearWaterPoints;
		static Setting* const uNearWaterRadius;
		static Setting* const uSurfaceFPS;

		static Setting* const sSurfaceTexture;

		static Setting* const fExteriorWaterReflectionThreshold;
		static Setting* const fInteriorWaterReflectionThreshold;
		static Setting* const fNearWaterIndoorTolerance;
		static Setting* const fNearWaterOutdoorTolerance;
		static Setting* const fNearWaterUnderwaterFreq;
		static Setting* const fNearWaterUnderwaterVolume;
		static Setting* const fRefractionWaterPlaneBias;
		static Setting* const fSurfaceTileSize;
		static Setting* const fTileTextureDivisor;
		static Setting* const fWadingWaterQuadSize;
		static Setting* const fWadingWaterTextureRes;
		static Setting* const fWaterGroupHeightRange;
	};

	struct Weather {
		static Setting* const bPrecipitation;

		static Setting* const sBumpFadeColor;
		static Setting* const sEnvReduceColor;
		static Setting* const sLerpCloseColor;

		static Setting* const fAlphaReduce;
		static Setting* const fSunBaseSize;
		static Setting* const fSunGlareSize;
	};

	static Setting* const bPrimitivesOn;
	static Setting* const bUseWaterHDR;

	static Setting* const iConcentricLengthMaxAverage;
	static Setting* const iConcentricLengthMaxEasy;
	static Setting* const iConcentricLengthMaxHard;
	static Setting* const iConcentricLengthMaxVeryEasy;
	static Setting* const iConcentricLengthMaxVeryHard;
	static Setting* const iConcentricLengthMinAverage;
	static Setting* const iConcentricLengthMinEasy;
	static Setting* const iConcentricLengthMinHard;
	static Setting* const iConcentricLengthMinVeryEasy;
	static Setting* const iConcentricLengthMinVeryHard;
	static Setting* const iDetectionHighNumPicks;
	static Setting* const iLastHDRSetting;
	static Setting* const iLowProcessingMilliseconds;
	static Setting* const iSweetSpotLengthMaxAverage;
	static Setting* const iSweetSpotLengthMaxEasy;
	static Setting* const iSweetSpotLengthMaxHard;
	static Setting* const iSweetSpotLengthMaxVeryEasy;
	static Setting* const iSweetSpotLengthMaxVeryHard;
	static Setting* const iSweetSpotLengthMinAverage;
	static Setting* const iSweetSpotLengthMinEasy;
	static Setting* const iSweetSpotLengthMinHard;
	static Setting* const iSweetSpotLengthMinVeryEasy;
	static Setting* const iSweetSpotLengthMinVeryHard;

	static Setting* const sDefaultTexAtlas;

	static Setting* const fAvoidanceAvoidNodeCost;
	static Setting* const fLowPerfCombatantVoiceDistance;
	static Setting* const fPC360ControllerMouseXMult;
	static Setting* const fPC360ControllerMouseYMult;
	static Setting* const fWeaponInteriorFarAttenuationMod;
	static Setting* const fWeaponInteriorFarVolumeMod;
	static Setting* const fWeaponInteriorNearAttenuationMod;
	static Setting* const fWeaponInteriorNearVolumeMod;

};