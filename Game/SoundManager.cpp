#include "stdafx.h"
#include "SoundManager.h"

namespace
{
	std::string SOUND_FILE_PATH = "Assets/sound/";	// サウンドのファイルパス。
	std::string SOUND_EXTENSION = ".wav";			// アニメーションの拡張子。

	/// <summary>
	/// サウンドファイルの再生オプションを表す構造体。
	/// </summary>
	struct SoundOption
	{
		const char* fileName;	// 再生したいファイルの名前。
		bool repeat = false;	// リピートするかどうか。（true=する、false=しない）
		float volume = 0.0f;	// 音量。

		/// <summary>
		/// サウンドファイルのフルパスを取得します。
		/// </summary>
		std::string GetFullPath() const
		{
			return SOUND_FILE_PATH + fileName + SOUND_EXTENSION;
		}
	};

	/// <summary>
	/// サウンドオプションの配列。
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
	g_soundEngine->ResistWaveFileBank(a, SOUND_OPTIONS[a].GetFullPath().c_str());	//c_strでstringからconst char*に変換。
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