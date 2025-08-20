#include "stdafx.h"
#include "SoundManager.h"

namespace
{
	const char* SOUND_FILE_PATH = "Assets/sound/";	// サウンドのファイルパス。

	struct SoundOption
	{
		const char* fileName;	// 再生したいファイルの名前。
		bool repeat = false;	// リピートするかどうか。（true=する、false=しない）
		float volume = 0.0f;	// 音量。

		// サウンドのファイルパスと各サウンドのファイル名を結合して返す。
		std::string GetFullPath() const
		{
			return std::string(SOUND_FILE_PATH) + fileName;
		}
	};

	const SoundOption SOUND_OPTIONS[] =
	{
		{ "title.wav", true, 1.0f },
		{ "inGame.wav", true, 1.0f },
		{ "gameClear.wav", true, 1.0f },
		{ "gameOver.wav", true, 1.0f },
		{ "push.wav", false, 3.5f },
		{ "countDownStart.wav", false, 3.5f },
		{ "jump.wav", false, 3.5f },
		{ "star.wav", false, 3.5f },
		{ "end.wav", false, 3.5f },
		{ "call.wav", false, 3.5f },
	};
}

void SoundManager::SoundNewGO(int a)
{
	sound[a] = NewGO<SoundSource>(0);
	g_soundEngine->ResistWaveFileBank(a, SOUND_OPTIONS[a].GetFullPath().c_str());	//c_strでstringからconst char*に変換。
	sound[a]->Init(a);
	sound[a]->Play(SOUND_OPTIONS[a].repeat);
	sound[a]->SetVolume(SOUND_OPTIONS[a].volume);
}

void SoundManager::SoundDeleteGO(int a)
{
	if (sound[a]) {
		DeleteGO(sound[a]);
		sound[a] = nullptr;
	}
}