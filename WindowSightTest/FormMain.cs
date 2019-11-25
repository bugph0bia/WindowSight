using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using AxWindowSightLib; // WindowSightコントロール用


namespace WindowSightTest
{
    public partial class FormMain : Form
    {
        public FormMain()
        {
            InitializeComponent();

            // イベントハンドラ登録
            axWindowSight.DragStart += new EventHandler(axWindowSight_DragStart);
            axWindowSight.DragEnd += new _DWindowSightEvents_DragEndEventHandler(axWindowSight_DragEnd);
            axWindowSight.ChangeTargetWindow += new _DWindowSightEvents_ChangeTargetWindowEventHandler(axWindowSight_ChangeTargetWindow);
        }

        /// <summary>
        /// FoundWindowボタン押下
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonGetFoundWindow_Click(object sender, EventArgs e)
        {
            textBoxFoundWindow.Text = "0x" + axWindowSight.FoundWindow.ToString("X8");
        }

        /// <summary>
        /// FlashFoundWindowボタン押下
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void buttonFlashFoundWindow_Click(object sender, EventArgs e)
        {
            axWindowSight.FlashFoundWindow();
        }

        /// <summary>
        /// axWindowSight DragStartイベント
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void axWindowSight_DragStart(object sender, EventArgs e)
        {
            textBoxLastEvent.Text = "DragStart";
            textBoxHwnd.Text = "";
        }

        /// <summary>
        /// axWindowSight DragEndイベント
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void axWindowSight_DragEnd(object sender, _DWindowSightEvents_DragEndEvent e)
        {
            textBoxLastEvent.Text = "DragEnd";
            textBoxHwnd.Text = "0x" + e.hWnd.ToString("X8");
        }

        /// <summary>
        /// axWindowSight ChangeTargetWindowイベント
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void axWindowSight_ChangeTargetWindow(object sender, _DWindowSightEvents_ChangeTargetWindowEvent e)
        {
            textBoxLastEvent.Text = "ChangeTargetWindow";
            textBoxHwnd.Text = "0x" + e.hWnd.ToString("X8");
        }
    }
}
