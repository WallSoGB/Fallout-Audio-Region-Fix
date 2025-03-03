#pragma once

class TESSound;

class BSGameSound {
public:
	BSGameSound();
	virtual				~BSGameSound();
	virtual bool		IsPlaying() const;
	virtual bool		GetState80000();
	virtual bool		GetState40();
	virtual float		GetVolume() const;
	virtual void		SetPaused(bool abSet);
	virtual void		SetEnvironmentType(uint32_t aeEnvironmentType);
	virtual bool		ComparePriority(uint32_t auiOtherPriority);
	virtual bool		PriorityTest(BSGameSound* apOtherSound);
	virtual bool		ReadFile();
	virtual void		Initialize();
	virtual void		Copy(BSGameSound*, bool);
	virtual bool		Start(bool abLoop);
	virtual bool		Stop();
	virtual bool		ResetPlayback();
	virtual bool		SetVolume(float afVolume);
	virtual void		Unk_10(); // Update position?
	virtual bool		Unk_11(bool);
	virtual bool		Unk_12(int); // Stub
	virtual bool		SetPosition(NiPoint3 akPos);
	virtual bool		SetPositionF(float afPosX, float afPosY, float afPosZ);
	virtual NiPoint3*	GetPosition(NiPoint3& arPos);
	virtual void		Unk_16(int, int, int); // Stub
	virtual void		SetDistances(float, float);
	virtual void		Unk_18(uint16_t, uint16_t, uint16_t, uint16_t, uint16_t);
	virtual bool		SetFrequency(float afFrequency);
	virtual float		GetFrequency() const;
	virtual void		Seek(uint32_t auiMilliseconds);

	enum SoundFlags {
		FLAG_2D								= 1 << 0,
		FLAG_3D								= 1 << 1,
		FLAG_VOICE							= 1 << 2,
		FLAG_FOOTSTEPS						= 1 << 3,
		FLAG_LOOP							= 1 << 4,
		FLAG_SYSTEM_SOUND					= 1 << 5,
		FLAG_RANDOM_FREQUENCY_SHIFT			= 1 << 6,
		FLAG_UNKBIT7						= 1 << 7,
		FLAG_UNKBIT8						= 1 << 8,
		FLAG_UNKBIT9						= 1 << 9,
		FLAG_UNKBIT10						= 1 << 10,
		FLAG_IS_MUSIC						= 1 << 11,
		FLAG_REGION_MUTE_WHEN_SUBMERGED		= 1 << 12,
		FLAG_MAYBE_UNDERWATER				= 1 << 13,
		FLAG_UNKBIT14						= 1 << 14,
		FLAG_CACHED							= 1 << 15,
		FLAG_DONT_CACHE						= 1 << 16,
		FLAG_UNKBIT17						= 1 << 17,
		FLAG_FIRST_PERSON					= 1 << 18,
		FLAG_MODULATED						= 1 << 19,
		FLAG_IS_RADIO						= 1 << 20,
		FLAG_IGNORE_TIMESCALE				= 1 << 21,
		FLAG_UNKBIT22						= 1 << 22,
		FLAG_UNKBIT23						= 1 << 23,
		FLAG_UNKBIT24						= 1 << 24,
		FLAG_ENVELOP_EFAST					= 1 << 25,
		FLAG_ENVELOPE_SLOW					= 1 << 26,
		FLAG_2DRADIUS						= 1 << 27,
		FLAG_UNKBIT28						= 1 << 28,
		FLAG_UNKBIT29						= 1 << 29,
		FLAG_ANIMATION_DRIVEN				= 1 << 30,
		FLAG_BEAM_EMITTER					= 1 << 31,
	};

	enum Flags00C {
		Flag_MuteWhenSubmerged		= 1 << 0,
		Flag_StartAtRandomPosition	= 1 << 1,
	};

	enum StateFlags {
		STATE_UNK_0		= 1 << 0,
		STATE_UNK_1		= 1 << 1,
		STATE_UNK_2		= 1 << 2,
		STATE_UNK_3		= 1 << 3,
		STATE_STOPPED	= 1 << 4,
		STATE_PLAYING	= 1 << 5,
		STATE_STOPPING	= 1 << 6,
		STATE_UNK_7		= 1 << 7,
		STATE_UNK_8		= 1 << 8,
		STATE_UNK_9		= 1 << 9,
		STATE_MUTED		= 1 << 10,
		STATE_UNK_11	= 1 << 11,
		STATE_UNK_12	= 1 << 12,
		STATE_UNK_13	= 1 << 13,
		STATE_UNK_14	= 1 << 14,
		STATE_UNK_15	= 1 << 15,
		STATE_UNK_16	= 1 << 16,
		STATE_PAUSED	= 1 << 17,
		STATE_UNK_18	= 1 << 18,
		STATE_UNK_19	= 1 << 19,
		STATE_UNK_20	= 1 << 20,
	};

	enum EnvironmentType { // Shifted by 1 compared to DSound ones
		ENVIRONMENT_NONE = 0,
		ENVIRONMENT_DEFAULT,
		ENVIRONMENT_GENERIC,
		ENVIRONMENT_PADDEDCELL,
		ENVIRONMENT_ROOM,
		ENVIRONMENT_BATHROOM,
		ENVIRONMENT_LIVINGROOM,
		ENVIRONMENT_STONEROOM,
		ENVIRONMENT_AUDITORIUM,
		ENVIRONMENT_CONCERTHALL,
		ENVIRONMENT_CAVE,
		ENVIRONMENT_ARENA,
		ENVIRONMENT_HANGAR,
		ENVIRONMENT_CARPETEDHALLWAY,
		ENVIRONMENT_HALLWAY,
		ENVIRONMENT_STONECORRIDOR,
		ENVIRONMENT_ALLEY,
		ENVIRONMENT_FOREST,
		ENVIRONMENT_CITY,
		ENVIRONMENT_MOUNTAINS,
		ENVIRONMENT_QUARRY,
		ENVIRONMENT_PLAIN,
		ENVIRONMENT_PARKINGLOT,
		ENVIRONMENT_SEWERPIPE,
		ENVIRONMENT_UNDERWATER,
		ENVIRONMENT_SMALLROOM,
		ENVIRONMENT_MEDIUMROOM,
		ENVIRONMENT_LARGEROOM,
		ENVIRONMENT_MEDIUMHALL,
		ENVIRONMENT_LARGEHALL,
		ENVIRONMENT_PLATE
	};

	uint32_t			uiID;
	Bitfield32			uiAudioFlags;
	Bitfield32			uiFlags00C;
	Bitfield32			uiStateFlags;
	uint32_t			uiDuration;
	uint16_t			usStaticAttenuation;
	uint16_t			usSystemAttenuation;
	uint16_t			usDistanceAttenuation;
	uint16_t			usFaderAttenuation;
	uint16_t			unk020;
	uint16_t			unk022;
	float				fVolume;
	float				flt028;
	float				flt02C;
	uint32_t			unk030;
	uint16_t			usSampleRate;
	char				cFilePath[254];
	TESSound*			pSourceSound;
	float				fFrequencyMod;
	float				fMaxAttenuationDist;
	float				fMinAttenuationDist;
	uint32_t			uiSourceID;
	uint32_t			uiAlternateID;
	uint32_t			uiChunkSizeInBytes;
	float				fListenerDistance;
	EnvironmentType		eEnvironmentType;
	uint8_t				cRandFrequencyShift;
	uint8_t				byte158;
	uint16_t			usSamplingFreq;
	uint32_t			unk15C;
	uint32_t			uiAudioDelayMS;
	void*				pCallback164;
	void*				pSoundStartCallback;
	uint32_t			time16C;
	uint32_t			time170;
	uint32_t			unk174;
	uint32_t			unk178;
	NiPoint3			kSomePosition17C;
	uint32_t			uiPriority;
	SoundMessageList	kMessageList;

	inline const char* GetFilePath() const { return cFilePath; }
	const char* GetEnvironmentTypeName() const;

	bool SetupPath(bool abSetID);

	void SetIsMuted(bool abMuted);

	inline bool Is2D() const { return uiAudioFlags.GetBit(FLAG_2D) && uiAudioFlags.GetBit(FLAG_2DRADIUS); }
	inline bool Is3D() const { return uiAudioFlags.GetBit(FLAG_3D); }

	bool GetFlag(SoundFlags auiFlag) const { return uiAudioFlags.GetBit(auiFlag); }
	void SetFlag(SoundFlags auiFlag, bool abSet) { uiAudioFlags.SetBit(auiFlag, abSet); }
	bool GetState(StateFlags auiFlag) const { return uiStateFlags.GetBit(auiFlag); }
	void SetState(StateFlags auiFlag, bool abSet) { uiStateFlags.SetBit(auiFlag, abSet); }
};

ASSERT_SIZE(BSGameSound, 0x198);