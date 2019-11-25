namespace WindowSightTest
{
    partial class FormMain
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージド リソースを破棄する場合は true を指定し、その他の場合は false を指定します。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(FormMain));
            this.textBoxFoundWindow = new System.Windows.Forms.TextBox();
            this.buttonFlashFoundWindow = new System.Windows.Forms.Button();
            this.buttonGetFoundWindow = new System.Windows.Forms.Button();
            this.groupBoxMethod = new System.Windows.Forms.GroupBox();
            this.groupBoxEvent = new System.Windows.Forms.GroupBox();
            this.labelHwnd = new System.Windows.Forms.Label();
            this.labelLastEvent = new System.Windows.Forms.Label();
            this.textBoxHwnd = new System.Windows.Forms.TextBox();
            this.textBoxLastEvent = new System.Windows.Forms.TextBox();
            this.groupBoxProperty = new System.Windows.Forms.GroupBox();
            this.axWindowSight = new AxWindowSightLib.AxWindowSight();
            this.groupBoxMethod.SuspendLayout();
            this.groupBoxEvent.SuspendLayout();
            this.groupBoxProperty.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axWindowSight)).BeginInit();
            this.SuspendLayout();
            // 
            // textBoxFoundWindow
            // 
            this.textBoxFoundWindow.Location = new System.Drawing.Point(180, 23);
            this.textBoxFoundWindow.Name = "textBoxFoundWindow";
            this.textBoxFoundWindow.ReadOnly = true;
            this.textBoxFoundWindow.Size = new System.Drawing.Size(100, 19);
            this.textBoxFoundWindow.TabIndex = 1;
            // 
            // buttonFlashFoundWindow
            // 
            this.buttonFlashFoundWindow.Location = new System.Drawing.Point(6, 18);
            this.buttonFlashFoundWindow.Name = "buttonFlashFoundWindow";
            this.buttonFlashFoundWindow.Size = new System.Drawing.Size(166, 28);
            this.buttonFlashFoundWindow.TabIndex = 0;
            this.buttonFlashFoundWindow.Text = "FlashFoundWindow";
            this.buttonFlashFoundWindow.UseVisualStyleBackColor = true;
            this.buttonFlashFoundWindow.Click += new System.EventHandler(this.buttonFlashFoundWindow_Click);
            // 
            // buttonGetFoundWindow
            // 
            this.buttonGetFoundWindow.Location = new System.Drawing.Point(6, 18);
            this.buttonGetFoundWindow.Name = "buttonGetFoundWindow";
            this.buttonGetFoundWindow.Size = new System.Drawing.Size(166, 28);
            this.buttonGetFoundWindow.TabIndex = 0;
            this.buttonGetFoundWindow.Text = "FoundWindow (Get)";
            this.buttonGetFoundWindow.UseVisualStyleBackColor = true;
            this.buttonGetFoundWindow.Click += new System.EventHandler(this.buttonGetFoundWindow_Click);
            // 
            // groupBoxMethod
            // 
            this.groupBoxMethod.Controls.Add(this.buttonFlashFoundWindow);
            this.groupBoxMethod.Location = new System.Drawing.Point(12, 123);
            this.groupBoxMethod.Name = "groupBoxMethod";
            this.groupBoxMethod.Size = new System.Drawing.Size(310, 61);
            this.groupBoxMethod.TabIndex = 2;
            this.groupBoxMethod.TabStop = false;
            this.groupBoxMethod.Text = "Method Test";
            // 
            // groupBoxEvent
            // 
            this.groupBoxEvent.Controls.Add(this.labelHwnd);
            this.groupBoxEvent.Controls.Add(this.labelLastEvent);
            this.groupBoxEvent.Controls.Add(this.textBoxHwnd);
            this.groupBoxEvent.Controls.Add(this.textBoxLastEvent);
            this.groupBoxEvent.Location = new System.Drawing.Point(12, 190);
            this.groupBoxEvent.Name = "groupBoxEvent";
            this.groupBoxEvent.Size = new System.Drawing.Size(310, 87);
            this.groupBoxEvent.TabIndex = 3;
            this.groupBoxEvent.TabStop = false;
            this.groupBoxEvent.Text = "Event Test";
            // 
            // labelHwnd
            // 
            this.labelHwnd.AutoSize = true;
            this.labelHwnd.Location = new System.Drawing.Point(6, 52);
            this.labelHwnd.Name = "labelHwnd";
            this.labelHwnd.Size = new System.Drawing.Size(82, 12);
            this.labelHwnd.TabIndex = 2;
            this.labelHwnd.Text = "Window Handle";
            // 
            // labelLastEvent
            // 
            this.labelLastEvent.AutoSize = true;
            this.labelLastEvent.Location = new System.Drawing.Point(6, 27);
            this.labelLastEvent.Name = "labelLastEvent";
            this.labelLastEvent.Size = new System.Drawing.Size(60, 12);
            this.labelLastEvent.TabIndex = 0;
            this.labelLastEvent.Text = "Last Event";
            // 
            // textBoxHwnd
            // 
            this.textBoxHwnd.Location = new System.Drawing.Point(94, 49);
            this.textBoxHwnd.Name = "textBoxHwnd";
            this.textBoxHwnd.ReadOnly = true;
            this.textBoxHwnd.Size = new System.Drawing.Size(123, 19);
            this.textBoxHwnd.TabIndex = 3;
            // 
            // textBoxLastEvent
            // 
            this.textBoxLastEvent.Location = new System.Drawing.Point(94, 24);
            this.textBoxLastEvent.Name = "textBoxLastEvent";
            this.textBoxLastEvent.ReadOnly = true;
            this.textBoxLastEvent.Size = new System.Drawing.Size(123, 19);
            this.textBoxLastEvent.TabIndex = 1;
            // 
            // groupBoxProperty
            // 
            this.groupBoxProperty.Controls.Add(this.buttonGetFoundWindow);
            this.groupBoxProperty.Controls.Add(this.textBoxFoundWindow);
            this.groupBoxProperty.Location = new System.Drawing.Point(12, 56);
            this.groupBoxProperty.Name = "groupBoxProperty";
            this.groupBoxProperty.Size = new System.Drawing.Size(310, 61);
            this.groupBoxProperty.TabIndex = 1;
            this.groupBoxProperty.TabStop = false;
            this.groupBoxProperty.Text = "Property Test";
            // 
            // axWindowSight
            // 
            this.axWindowSight.Enabled = true;
            this.axWindowSight.Location = new System.Drawing.Point(20, 12);
            this.axWindowSight.Name = "axWindowSight";
            this.axWindowSight.OcxState = ((System.Windows.Forms.AxHost.State)(resources.GetObject("axWindowSight.OcxState")));
            this.axWindowSight.Size = new System.Drawing.Size(31, 28);
            this.axWindowSight.TabIndex = 0;
            // 
            // FormMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(345, 298);
            this.Controls.Add(this.axWindowSight);
            this.Controls.Add(this.groupBoxEvent);
            this.Controls.Add(this.groupBoxProperty);
            this.Controls.Add(this.groupBoxMethod);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "FormMain";
            this.Text = "WindowSight Test";
            this.groupBoxMethod.ResumeLayout(false);
            this.groupBoxEvent.ResumeLayout(false);
            this.groupBoxEvent.PerformLayout();
            this.groupBoxProperty.ResumeLayout(false);
            this.groupBoxProperty.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.axWindowSight)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.TextBox textBoxFoundWindow;
        private System.Windows.Forms.Button buttonFlashFoundWindow;
        private System.Windows.Forms.Button buttonGetFoundWindow;
        private System.Windows.Forms.GroupBox groupBoxMethod;
        private System.Windows.Forms.GroupBox groupBoxEvent;
        private System.Windows.Forms.Label labelHwnd;
        private System.Windows.Forms.Label labelLastEvent;
        private System.Windows.Forms.TextBox textBoxHwnd;
        private System.Windows.Forms.TextBox textBoxLastEvent;
        private System.Windows.Forms.GroupBox groupBoxProperty;
        private AxWindowSightLib.AxWindowSight axWindowSight;
    }
}

