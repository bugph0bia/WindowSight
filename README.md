WindowSight
===

![Software Version](http://img.shields.io/badge/Version-v1.0.0-green.svg?style=flat)
![Python Version](http://img.shields.io/badge/VisualStudio-2019-blue.svg?style=flat)
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)

## 概要
ウィンドウをピックアップするための、Spy++ に搭載されているコントロールのように使用できる ActiveX コントロール。  

## バージョン
v1.0.0

## 開発環境
Visual Studio 2019

## ライセンス
MIT License

## インストール／アンインストール
### インストール方法
- Windows (x86) の場合
    1. WindowSight.ocxを任意のフォルダを配置する。
    2. 管理者権限でコマンドプロンプトを起動する。
    3. `regsvr32 WindowSight.ocx` を実行。
- Windows (x64) の場合
    1. WindowSight.ocxを任意のフォルダを配置する。
    2. 管理者権限でコマンドプロンプトを起動する。
    3. `C:\Windows\SysWow64\regsvr32 WindowSight.ocx` を実行。

### アンインストール方法
- Windows (x86) の場合
    1. WindowSight.ocxを任意のフォルダを配置する。
    2. 管理者権限でコマンドプロンプトを起動する。
    3. `regsvr32 /u WindowSight.ocx` を実行。
- Windows (x64) の場合
    1. WindowSight.ocxを任意のフォルダを配置する。
    2. 管理者権限でコマンドプロンプトを起動する。
    3. `C:\Windows\SysWow64\regsvr32 /u WindowSight.ocx` を実行。

## リファレンス
### プロパティ
- **FoundWindow**
    - 説明：WindowSight内で保持している発見済みウィンドウのハンドル値。
    - 備考：通常 Get で使用する。Set も可能だが実用上の意味は無い。

### メソッド
- **FlashFoundWindow**
    - 説明：WindowSight内で保持している発見済みウィンドウを点滅させる。どのウィンドウを保持しているか分からなくなった場合のヘルプ機能。

### イベント
- **DragStart**
    - 説明：ドラッグ開始イベント
- **DragEnd**
    - 説明：ドラッグ終了イベント
    - 引数：OLE_HANDLE - 最後に保持していたウィンドウのハンドル値
- **ChangeTargetWindow**
    - 説明：ドラッグ中の対象ウィンドウ変化イベント
    - 引数：OLE_HANDLE - 新しく対象となったウィンドウのハンドル値

## メモ
- ActiveXコントロールは時代遅れかもしれないが、C++/MFCアプリ や C# フォームアプリなどで汎用的に使用できるためまだまだ現役の印象。
- ただし、Visual Studio の C++/MFC での ActiveXコントロールの開発および使用はかなり行いにくくなっている。もはや非サポートというレベル。
    - ActiveXコントロール開発時にウィザードが作成するコードもあまりスマートではない印象。結局、自動生成されたコードを手動で修正した部分がある。
        - プロパティを追加したときにidlファイルへ追加されるコードが以前と異なった。
        - インデントが整っていなかったり関数宣言の追加位置がバラバラであったり。
    - Issue #3 にも書いたが、ActiveXコントロールをMFCアプリケーションで使用する際にうまくいかなかった。
        - プロパティ/メソッドは IDispatch ラッパークラスが自動生成され、その中にメンバ関数が定義されることで使用可能となるはずが、メンバ関数が定義されなかった。
        - イベントは問題なかった。
    - Visual C++ 6.0 で開発していた頃は問題なくできていたことができなくなっている。
    - C# フォームアプリだと問題なかった。
- x64版もビルドしたが使用できなかった。要調査。
