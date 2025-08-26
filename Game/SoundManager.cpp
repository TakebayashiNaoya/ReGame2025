#include "stdafx.h"
#include "SoundManager.h"

namespace
{
	std::string SOUND_FILE_PATH = "Assets/sound/";	// �T�E���h�̃t�@�C���p�X�B
	std::string SOUND_EXTENSION = ".wav";			// �A�j���[�V�����̊g���q�B

	/// <summary>
	/// �T�E���h�t�@�C���̍Đ��I�v�V������\���\���́B
	/// </summary>
	struct SoundOption
	{
		const char* fileName;	// �Đ��������t�@�C���̖��O�B
		bool repeat = false;	// ���s�[�g���邩�ǂ����B�itrue=����Afalse=���Ȃ��j
		float volume = 0.0f;	// ���ʁB

		/// <summary>
		/// �T�E���h�t�@�C���̃t���p�X���擾���܂��B
		/// </summary>
		std::string GetFullPath() const
		{
			return SOUND_FILE_PATH + fileName + SOUND_EXTENSION;
		}
	};

	/// <summary>
	/// �T�E���h�I�v�V�����̔z��B
	/// </summary>
	const SoundOption SOUND_OPTIONS[] =
	{
		{ "title", true, 1.0f },
		{ "inGame", true, 1.0f },
		{ "gameClear", true, 1.0f },
		{ "gameOver", true, 1.0f },
		{ "push", false, 3.5f },
		{ "countDownStart", false, 3.5f },
		{ "jump", false, 3.5f },
		{ "star", false, 3.5f },
		{ "end", false, 3.5f },
		{ "call", false, 3.5f },
	};
}

void SoundManager::SoundNewGO(int a)
{
	sound[a] = NewGO<SoundSource>(0);
	g_soundEngine->ResistWaveFileBank(a, SOUND_OPTIONS[a].GetFullPath().c_str());	//c_str��string����const char*�ɕϊ��B
	sound[a]->Init(a);
	sound[a]->Play(SOUND_OPTIONS[a].repeat);
	sound[a]->SetVolume(SOUND_OPTIONS[a].volume);
}

void SoundManager::SoundDeleteGO(int a)
{
	if (this != nullptr)
	{
		DeleteGO(sound[a]);
	}
}