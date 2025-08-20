/// <summary>
/// サウンドを管理するクラス。
/// </summary>
#pragma once
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"

enum EnSoundList
{
	enSoundList_TitleBGM,		// タイトルで再生するBGM。
	enSoundList_InGameBGM,		// インゲームで再生するBGM。
	enSoundList_GameClearBGM,	// ゲームクリアで再生するBGM。
	enSoundList_GameOverBGM,	// ゲームオーバーで再生するBGM。
	enSoundList_SelectSE,		// PUSH(A)でAを押したときに再生するSE。
	enSoundList_CountDownSE,	// ゲーム開始時に再生するカウントダウンのSE。
	enSoundList_JumpSE,			// プレイヤーがジャンプしたときに再生するSE。
	enSoundList_StarGetSE,		// スターを取得したときに再生するSE。
	enSoundList_EndSE,			// タイムアップで終了するときに再生するSE。
	enSoundList_CallSE,			// リザルト表示時に再生する歓声SE。
	enSoundList_Num
};

class SoundManager :public IGameObject
{
public:
	/// <summary>
	/// 新しいゲームオブジェクトのサウンドを開始します。
	/// </summary>
	/// <param name="a">サウンドを開始するゲームオブジェクトの識別子。</param>
	void SoundNewGO(int a);

	/// <summary>
	/// 指定されたIDのサウンドオブジェクトを削除します。
	/// </summary>
	/// <param name="a">削除するサウンドオブジェクトのID。</param>
	void SoundDeleteGO(int a);

private:
	SoundSource* sound[enSoundList_Num];	// enSoundList_Num 個の SoundSource オブジェクトへのポインタを格納する配列です。
};

