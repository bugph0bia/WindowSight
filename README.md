WindowSight
===

![Software Version](http://img.shields.io/badge/Version-v1.0.1-green.svg?style=flat)
![VS Version](http://img.shields.io/badge/VisualStudio-2019-blue.svg?style=flat)
[![MIT License](http://img.shields.io/badge/license-MIT-blue.svg?style=flat)](LICENSE)

## 概要
ウィンドウをピックアップするためのActiveX コントロール。Spy++ に搭載されているコントロールのように使用可能。  

![use](https://user-images.githubusercontent.com/18702413/69725860-81c72280-1162-11ea-9fd4-0e3412c9b112.gif)  
（ウィンドウ左上の照準のようなコントロール）  

## バージョン
v1.0.1

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

※レジストリにファイルパスが登録されるため、インストール後に WindowSight.ocx ファイルを移動すると使用できなくなる。

### アンインストール方法
- Windows (x86) の場合
    1. 管理者権限でコマンドプロンプトを起動する。
    2. `regsvr32 /u WindowSight.ocx` を実行。
- Windows (x64) の場合
    1. 管理者権限でコマンドプロンプトを起動する。
    2. `C:\Windows\SysWow64\regsvr32 /u WindowSight.ocx` を実行。

## 使用方法
### C++ / MFCアプリケーション (on Visual Studio 2019)
1. ダイアログへのコントールの挿入方法
    1. リソースビューからダイアログエディタを開く。
    2. ダイアログ上で右クリックして「ActiveXコントロールの挿入...」を選択。
    3. 「ActiveXコントロールの挿入」画面から「WindowSight Control」を選択して「OK」ボタンを押下。
2. プロパティ／メソッドの追加方法
    1. 挿入した WindowSight コントロールを右クリックして「変数の追加...」を選択してコントロール変数を追加する。
    2. プロジェクトに自動的に IDispatch ラッパークラスが挿入され、そのクラスの型のコントロール変数が追加される。
       ラッパークラスのメンバ関数にプロパティの Getter/Setter とメソッドが用意された状態となる。
        - ・・・はずだが、VisualStudio 2017 / 2019 ではうまくいかない。2013では問題なし。
3. イベントハンドラの追加方法
    1. 挿入した WindowSight コントロールを右クリックして「イベントハンドラーの追加...」を選択する。
    2. 表示されたウィザードで追加したいイベントとハンドラのメンバ関数を指定して挿入する。

### C# / Windowsフォームアプリケーション (on Visual Studio 2019)
1. フォームへのコントロールの挿入方法
    1. ソリューションエクスプローラーからフォームのデザイナを開く。
    2. ツールボックスの何もない領域で右クリックして「アイテムの選択...」を選択する。
    3. 「ツールボックスアイテムの選択」画面の「COMコンポーネント」タブを開き、「WindowSight Control」にチェックを付けて「OK」ボタンを押下。
    4. ツールボックス内に「WindowSight Control」が追加されるのでフォームへ挿入する。
    5. 挿入に失敗する場合は、「プロジェクト」メニューの「参照の追加...」の「COM」ページから「WindowSightLib」にチェックを付けて「OK」ボタンを押下してから試す。
2. プロパティ／メソッドの追加方法
    1. コントロールの挿入を行うことでプロジェクトの参照に AxWindowsSightクラス（AxWindowSightLib名前空間 - AxWindowSightクラス）が追加されており、
       コントロール変数はそのクラスの型となっている。プロパティとメソッドも追加されているため使用可能な状態となる。
3. イベントハンドラの追加方法
    1. AxWindowsSightクラス（AxWindowSightLib名前空間 - AxWindowSightクラス）に追加されているイベント変数とデリゲート型を利用することでイベントハンドラ関数を追加可能。

[C#サンプルアプリケーション](/WindowSightTest)

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
