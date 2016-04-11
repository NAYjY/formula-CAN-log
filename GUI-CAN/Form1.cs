using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data; 
using System.Drawing;
using System.Linq;
using System.Text;
using System.Timers; 
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.IO;

namespace WindowsFormsApplication6
{
    public partial class Form1 : Form
    {
        int arr = 0; //Arrow
        int i = 0;
        float AcX, AcY, AcZ;
        int FL, FR, BL, BR;
        float Yaw, Pitch, Roll, Lat, Long;
        string line,linetxt;
        int yax = 0;
        int CFR , CFL , CBR , CBL;
        bool tt = false;
        float rr = 0;
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            Application.Idle += new EventHandler(MainCode);


        }
        
        private void Form1_Load(object sender, EventArgs e)
        {

            string[] strPortNames = SerialPort.GetPortNames();
            foreach (string n in strPortNames)
            {
                ForComPort.Items.Add(n);
            }

            



        }
        void MainCode(object sender, EventArgs e)
        {
            Random r = new Random();

           
        }
       
      

        private void labelCom_Click(object sender, EventArgs e)
        {

        }

        private void ForComPort_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void OpenSerialButton_Click(object sender, EventArgs e)
        {
            if (File.Exists(textBox18.Text))
            {
                textBox18.Text = "File exist.";
            }
            ForComPort.SelectedIndex = 0;
            serialPort1.PortName = ForComPort.SelectedItem + "";
            serialPort1.Open();
        }

        private void SerialHexData_TextChanged(object sender, EventArgs e)
        {

        }

        int ia = 0;
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            line = serialPort1.ReadLine();
            SerialHexData.AppendText(line);
            SerialHexData.AppendText("\r\n");
            
           
            Console.WriteLine(ia++);
            //Create the file.
            using (System.IO.StreamWriter file =
            new System.IO.StreamWriter(@textBox18.Text, true))
            {
                file.WriteLine(line);
            }
            MessageSap(line);
        }



        private void buttonClose_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }

        private void tabPage2_Click(object sender, EventArgs e)
        {

        }

        private void tabPage1_Click(object sender, EventArgs e)
        {

        }

        private void textBox16_TextChanged(object sender, EventArgs e)
        {

        }

        private void label33_Click(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            int size = -1;
            DialogResult result = openFileDialog1.ShowDialog(); // Show the dialog.
            if (result == DialogResult.OK) // Test result.
            {
                string file = openFileDialog1.FileName;
                try
                {
                    string text = File.ReadAllText(file);
                    size = text.Length;
                    textBox17.AppendText(file);
                }
                catch (IOException)
                {
                }
            }
            Console.WriteLine(size); // <-- Shows file size in debugging mode.
            Console.WriteLine(result); // <-- For debugging use.
        }

        private void button3_Click(object sender, EventArgs e)
        {
            string savePath = textBox18.Text;
        }

        private void textBox18_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox17_TextChanged(object sender, EventArgs e)
        {

        }



        private void button5_Click(object sender, EventArgs e)
        {
            
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox14_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox15_TextChanged(object sender, EventArgs e)
        {

        }

        private void chart4_Click(object sender, EventArgs e)
        {

        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }

        private void textBox19_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }


        /* private void DrawPolygonPoint(object sender, PaintEventArgs e)
         {


             // Create pen.
             Pen blackPen = new Pen(Color.Lime, 6);

             // Create points that define polygon.
             Point point1 = new Point(620, 320);
             Point point2 = new Point(630, 320);
             Point point3 = new Point(640, 320);
             Point point4 = new Point(650, 320); 
             Point point5 = new Point(660, 320);
             Point point6 = new Point(670, 320);
             Point point7 = new Point(680, 320);
             Point point8 = new Point(690, 320);
             Point point9 = new Point(700, 320);
             Point point10 = new Point(700, 320);
             Point point11 = new Point(700, 330);
             Point point12 = new Point(700, 340);
             Point point13 = new Point(700, 350);
             Point point14 = new Point(680, 350);
             Point point15 = new Point(660, 350);
             Point point16 = new Point(640, 350);
             Point point17 = new Point(620, 350);
             Point point18 = new Point(620, 340);
             Point point19 = new Point(620, 330);
             //Point point20 = new Point(620, 320);
             Point point20 = new Point(820, 520);

             Point[] curvePoints = { point1, point2, point3, point4, point5, point6, point7, point8, point9, point10, point11, point12, point13, point14, point15, point16, point17, point18, point19, point20 };

             // Draw polygon to screen.
             e.Graphics.DrawPolygon(blackPen, curvePoints);
         }*/


        public void button2_Click_1(object sender, EventArgs e)
        {
            Pen blackPen = new Pen(Color.Lime, 6);
            System.Drawing.Point[] p = new System.Drawing.Point[10];
            Graphics gr = this.CreateGraphics();
            p[0].X = 20;
            p[0].Y = 20;
            p[1].X = 20;
            p[1].Y = 150;
            p[2].X = 150;
            p[2].Y = 150;
            p[3].X = 150;
            p[3].Y = 20;
            /*p[4].X = 70;
            p[4].Y = 160;
            p[5].X = 90;
            p[5].Y = 160;
            p[6].X = 100;
            p[6].Y = 140;
            p[7].X = 100;
            p[7].Y = 120;
            p[8].X = 90;
            p[8].Y = 130;
            p[9].X = 70;
            p[9].Y = 150;*/

            gr = pictureBox5.CreateGraphics();
            gr.DrawPolygon(blackPen, p);

        }
        private void Modelabsorber1(int MFL)
        {

            if (MFL == 0)
            {
                pictureBox1.Image = imageList1.Images[0];

            }
            else if (MFL == 1)
            {
                pictureBox1.Image = imageList1.Images[1];

            }
            else if (MFL == 2)
            {
                pictureBox1.Image = imageList1.Images[2];

            }
            else if (MFL == 3)
            {
                pictureBox1.Image = imageList1.Images[3];


            }
            else if (MFL == 4)
            {
                pictureBox1.Image = imageList1.Images[4];



            }
            else if (MFL == 5)
            {
                pictureBox1.Image = imageList1.Images[5];

            }

            else if (MFL == 6)
            {
                pictureBox1.Image = imageList1.Images[6];

            }
            else if (MFL == 7)
            {
                pictureBox1.Image = imageList1.Images[7];

            }
            else if (MFL == 8)
            {
                pictureBox1.Image = imageList1.Images[8];

            }
            else if (MFL == 9)
            {
                pictureBox1.Image = imageList1.Images[9];


            }
            else if (MFL == 10)
            {
                pictureBox1.Image = imageList1.Images[10];



            }
            else if (MFL == 11)
            {
                pictureBox1.Image = imageList1.Images[11];

            }
            else if (MFL == 12)
            {
                pictureBox1.Image = imageList1.Images[12];
            }
            else if (MFL == 13)
            {
                pictureBox1.Image = imageList1.Images[13];

            }

            else if (MFL == 14)
            {
                pictureBox1.Image = imageList1.Images[14];

            }
            else if (MFL == 15)
            {
                pictureBox1.Image = imageList1.Images[15];

            }
            else if (MFL == -1)
            {
                pictureBox1.Image = imageList1.Images[16];

            }
            else if (MFL == -2)
            {
                pictureBox1.Image = imageList1.Images[17];

            }
            else if (MFL == -3)
            {
                pictureBox1.Image = imageList1.Images[18];


            }
            else if (MFL == -4)
            {
                pictureBox1.Image = imageList1.Images[19];

            }
            else if (MFL == -5)
            {
                pictureBox1.Image = imageList1.Images[20];

            }

            else if (MFL == -6)
            {
                pictureBox1.Image = imageList1.Images[21];

            }
            else if (MFL == -7)
            {
                pictureBox1.Image = imageList1.Images[22];

            }
            else if (MFL == -8)
            {
                pictureBox1.Image = imageList1.Images[23];

            }
            else if (MFL == -9)
            {
                pictureBox1.Image = imageList1.Images[24];

            }
            else if (MFL == -10)
            {
                pictureBox1.Image = imageList1.Images[25];

            }
            else if (MFL == -11)
            {
                pictureBox1.Image = imageList1.Images[26];

            }
            else if (MFL == -12)
            {
                pictureBox1.Image = imageList1.Images[27];

            }
            else if (MFL == -13)
            {
                pictureBox1.Image = imageList1.Images[28];

            }

            else if (MFL == -14)
            {
                pictureBox1.Image = imageList1.Images[29];

            }
            else if (MFL == -15)
            {
                pictureBox1.Image = imageList1.Images[30];

            }

        }
        private void Modelabsorber2(int MFR)
        {

            if (MFR == 0)
            {
                pictureBox2.Image = imageList1.Images[0];

            }
            else if (MFR == 1)
            {
                pictureBox2.Image = imageList1.Images[1];

            }
            else if (MFR == 2)
            {
                pictureBox2.Image = imageList1.Images[2];

            }
            else if (MFR == 3)
            {
                pictureBox2.Image = imageList1.Images[3];


            }
            else if (MFR == 4)
            {
                pictureBox2.Image = imageList1.Images[4];



            }
            else if (MFR == 5)
            {
                pictureBox2.Image = imageList1.Images[5];

            }

            else if (MFR == 6)
            {
                pictureBox2.Image = imageList1.Images[6];

            }
            else if (MFR == 7)
            {
                pictureBox2.Image = imageList1.Images[7];

            }
            else if (MFR == 8)
            {
                pictureBox2.Image = imageList1.Images[8];

            }
            else if (MFR == 9)
            {
                pictureBox2.Image = imageList1.Images[9];


            }
            else if (MFR == 10)
            {
                pictureBox2.Image = imageList1.Images[10];



            }
            else if (MFR == 11)
            {
                pictureBox2.Image = imageList1.Images[11];

            }
            else if (MFR == 12)
            {
                pictureBox2.Image = imageList1.Images[12];
            }
            else if (MFR == 13)
            {
                pictureBox2.Image = imageList1.Images[13];

            }

            else if (MFR == 14)
            {
                pictureBox2.Image = imageList1.Images[14];

            }
            else if (MFR == 15)
            {
                pictureBox2.Image = imageList1.Images[15];

            }
            else if (MFR == -1)
            {
                pictureBox2.Image = imageList1.Images[16];

            }
            else if (MFR == -2)
            {
                pictureBox2.Image = imageList1.Images[17];

            }
            else if (MFR == -3)
            {
                pictureBox2.Image = imageList1.Images[18];


            }
            else if (MFR == -4)
            {
                pictureBox2.Image = imageList1.Images[19];

            }
            else if (MFR == -5)
            {
                pictureBox2.Image = imageList1.Images[20];

            }

            else if (MFR == -6)
            {
                pictureBox2.Image = imageList1.Images[21];

            }
            else if (MFR == -7)
            {
                pictureBox2.Image = imageList1.Images[22];

            }
            else if (MFR == -8)
            {
                pictureBox2.Image = imageList1.Images[23];

            }
            else if (MFR == -9)
            {
                pictureBox2.Image = imageList1.Images[24];

            }
            else if (MFR == -10)
            {
                pictureBox2.Image = imageList1.Images[25];

            }
            else if (MFR == -11)
            {
                pictureBox2.Image = imageList1.Images[26];

            }
            else if (MFR == -12)
            {
                pictureBox2.Image = imageList1.Images[27];

            }
            else if (MFR == -13)
            {
                pictureBox2.Image = imageList1.Images[28];

            }

            else if (MFR == -14)
            {
                pictureBox2.Image = imageList1.Images[29];

            }
            else if (MFR == -15)
            {
                pictureBox2.Image = imageList1.Images[30];

            }

        }
        private void Modelabsorber3(int MBL)
        {

            if (MBL == 0)
            {
                pictureBox3.Image = imageList1.Images[0];

            }
            else if (MBL == 1)
            {
                pictureBox3.Image = imageList1.Images[1];

            }
            else if (MBL == 2)
            {
                pictureBox3.Image = imageList1.Images[2];

            }
            else if (MBL == 3)
            {
                pictureBox3.Image = imageList1.Images[3];


            }
            else if (MBL == 4)
            {
                pictureBox3.Image = imageList1.Images[4];



            }
            else if (MBL == 5)
            {
                pictureBox3.Image = imageList1.Images[5];

            }

            if (MBL == 6)
            {
                pictureBox3.Image = imageList1.Images[6];

            }
            else if (MBL == 7)
            {
                pictureBox3.Image = imageList1.Images[7];

            }
            else if (MBL == 8)
            {
                pictureBox3.Image = imageList1.Images[8];

            }
            else if (MBL == 9)
            {
                pictureBox3.Image = imageList1.Images[9];


            }
            else if (MBL == 10)
            {
                pictureBox3.Image = imageList1.Images[10];



            }
            else if (MBL == 11)
            {
                pictureBox3.Image = imageList1.Images[11];

            }
            if (MBL == 12)
            {
                pictureBox3.Image = imageList1.Images[12];
            }
            else if (MBL == 13)
            {
                pictureBox3.Image = imageList1.Images[13];

            }

            else if (MBL == 14)
            {
                pictureBox3.Image = imageList1.Images[14];

            }
            else if (MBL == 15)
            {
                pictureBox3.Image = imageList1.Images[15];

            }
            else if (MBL == -1)
            {
                pictureBox3.Image = imageList1.Images[16];

            }
            else if (MBL == -2)
            {
                pictureBox3.Image = imageList1.Images[17];

            }
            else if (MBL == -3)
            {
                pictureBox3.Image = imageList1.Images[18];


            }
            else if (MBL == -4)
            {
                pictureBox3.Image = imageList1.Images[19];

            }
            else if (MBL == -5)
            {
                pictureBox3.Image = imageList1.Images[20];

            }

            else if (MBL == -6)
            {
                pictureBox3.Image = imageList1.Images[21];

            }
            else if (MBL == -7)
            {
                pictureBox3.Image = imageList1.Images[22];

            }
            else if (MBL == -8)
            {
                pictureBox3.Image = imageList1.Images[23];

            }
            else if (MBL == -9)
            {
                pictureBox3.Image = imageList1.Images[24];

            }
            else if (MBL == -10)
            {
                pictureBox3.Image = imageList1.Images[25];

            }
            else if (MBL == -11)
            {
                pictureBox3.Image = imageList1.Images[26];

            }
            else if (MBL == -12)
            {
                pictureBox3.Image = imageList1.Images[27];

            }
            else if (MBL == -13)
            {
                pictureBox3.Image = imageList1.Images[28];

            }

            else if (MBL == -14)
            {
                pictureBox3.Image = imageList1.Images[29];

            }
            else if (MBL == -15)
            {
                pictureBox3.Image = imageList1.Images[30];

            }

        }
        private void Modelabsorber4(int MBR)
        {

            if (MBR == 0)
            {
                pictureBox4.Image = imageList1.Images[0];

            }
            else if (MBR == 1)
            {
                pictureBox4.Image = imageList1.Images[1];

            }
            else if (MBR == 2)
            {
                pictureBox4.Image = imageList1.Images[2];

            }
            else if (MBR == 3)
            {
                pictureBox4.Image = imageList1.Images[3];


            }
            else if (MBR == 4)
            {
                pictureBox4.Image = imageList1.Images[4];



            }
            else if (MBR == 5)
            {
                pictureBox4.Image = imageList1.Images[5];

            }

            if (MBR == 6)
            {
                pictureBox4.Image = imageList1.Images[6];

            }
            else if (MBR == 7)
            {
                pictureBox4.Image = imageList1.Images[7];

            }
            else if (MBR == 8)
            {
                pictureBox4.Image = imageList1.Images[8];

            }
            else if (MBR == 9)
            {
                pictureBox4.Image = imageList1.Images[9];


            }
            else if (MBR == 10)
            {
                pictureBox4.Image = imageList1.Images[10];



            }
            else if (MBR == 11)
            {
                pictureBox4.Image = imageList1.Images[11];

            }
            if (MBR == 12)
            {
                pictureBox4.Image = imageList1.Images[12];
            }
            else if (MBR == 13)
            {
                pictureBox4.Image = imageList1.Images[13];

            }

            else if (MBR == 14)
            {
                pictureBox4.Image = imageList1.Images[14];

            }
            else if (MBR == 15)
            {
                pictureBox4.Image = imageList1.Images[15];

            }
            else if (MBR == -1)
            {
                pictureBox4.Image = imageList1.Images[16];

            }
            else if (MBR == -2)
            {
                pictureBox4.Image = imageList1.Images[17];

            }
            else if (MBR == -3)
            {
                pictureBox4.Image = imageList1.Images[18];


            }
            else if (MBR == -4)
            {
                pictureBox4.Image = imageList1.Images[19];

            }
            else if (MBR == -5)
            {
                pictureBox4.Image = imageList1.Images[20];

            }

            else if (MBR == -6)
            {
                pictureBox4.Image = imageList1.Images[21];

            }
            else if (MBR == -7)
            {
                pictureBox4.Image = imageList1.Images[22];

            }
            else if (MBR == -8)
            {
                pictureBox4.Image = imageList1.Images[23];

            }
            else if (MBR == -9)
            {
                pictureBox4.Image = imageList1.Images[24];

            }
            else if (MBR == -10)
            {
                pictureBox4.Image = imageList1.Images[25];

            }
            else if (MBR == -11)
            {
                pictureBox4.Image = imageList1.Images[26];

            }
            else if (MBR == -12)
            {
                pictureBox4.Image = imageList1.Images[27];

            }
            else if (MBR == -13)
            {
                pictureBox4.Image = imageList1.Images[28];

            }

            else if (MBR == -14)
            {
                pictureBox4.Image = imageList1.Images[29];

            }
            else if (MBR == -15)
            {
                pictureBox4.Image = imageList1.Images[30];

            }

        }
        /*private void Arrow()
        {
            for (jj = 0; jj < 25; jj++)
            {

                if (arr > 0 && arr < 8)
                {
                    pictureBox6.Image = imageList2.Images[0];
                    timer1.Stop();
                }
                else if (arr >= 8 && arr < 23)
                {
                    pictureBox6.Image = imageList2.Images[1];
                    timer1.Stop();
                }
                else if (arr >= 23 && arr < 38)
                {
                    pictureBox6.Image = imageList2.Images[2];
                    timer1.Stop();
                }
                else if (arr >= 38 && arr < 53)
                {
                    pictureBox6.Image = imageList2.Images[3];
                    timer1.Stop();
                }
                else if (arr >= 53 && arr < 68)
                {
                    pictureBox6.Image = imageList2.Images[4];
                    timer1.Stop();
                }
                else if (arr >= 68 && arr < 83)
                {
                    pictureBox6.Image = imageList2.Images[5];
                    timer1.Stop();
                }
                else if (arr >= 83 && arr < 98)
                {
                    pictureBox6.Image = imageList2.Images[6];
                    timer1.Stop();
                }
                else if (arr >= 98 && arr < 113)
                {
                    pictureBox6.Image = imageList2.Images[7];
                    timer1.Stop();
                }
                else if (arr >= 113 && arr < 127)
                {
                    pictureBox6.Image = imageList2.Images[8];
                    timer1.Stop();
                }
                else if (arr >= 127 && arr < 143)
                {
                    pictureBox6.Image = imageList2.Images[9];
                    timer1.Stop();
                }
                else if (arr >= 143 && arr < 158)
                {
                    pictureBox6.Image = imageList2.Images[10];
                    timer1.Stop();
                }
                else if (arr >= 158 && arr < 173)
                {
                    pictureBox6.Image = imageList2.Images[11];
                    timer1.Stop();
                }
                else if (arr >= 173 && arr < 188)
                {
                    pictureBox6.Image = imageList2.Images[12];
                    timer1.Stop();
                }
                else if (arr >= 188 && arr < 203)
                {
                    pictureBox6.Image = imageList2.Images[13];
                    timer1.Stop();
                }
                else if (arr >= 203 && arr < 218)
                {
                    pictureBox6.Image = imageList2.Images[14];
                    timer1.Stop();
                }
                else if (arr >= 218 && arr < 233)
                {
                    pictureBox6.Image = imageList2.Images[15];
                    timer1.Stop();
                }
                else if (arr >= 233 && arr < 248)
                {
                    pictureBox6.Image = imageList2.Images[16];
                    timer1.Stop();
                }
                else if (arr >= 248 && arr < 263)
                {
                    pictureBox6.Image = imageList2.Images[17];
                    timer1.Stop();
                }
                else if (arr >= 263 && arr < 278)
                {
                    pictureBox6.Image = imageList2.Images[18];
                    timer1.Stop();
                }
                else if (arr >= 278 && arr < 293)
                {
                    pictureBox6.Image = imageList2.Images[19];
                    timer1.Stop();
                }
                else if (arr >= 293 && arr < 308)
                {
                    pictureBox6.Image = imageList2.Images[20];
                    timer1.Stop();
                }
                else if (arr >= 308 && arr < 323)
                {
                    pictureBox6.Image = imageList2.Images[21];
                    timer1.Stop();
                }
                else if (arr >= 323 && arr < 338)
                {
                    pictureBox6.Image = imageList2.Images[22];
                    timer1.Stop();
                }
                else if (arr >= 338 && arr < 353)
                {
                    pictureBox6.Image = imageList2.Images[23];
                    timer1.Stop();
                }
                else if (arr >= 353 && arr < 360)
                {
                    pictureBox6.Image = imageList2.Images[24];
                    timer1.Stop();
                }
            }
        }*/
        private float Hextofloat(string lines)
        {
            //string hexString = "43480170";
            ulong num = ulong.Parse(lines, System.Globalization.NumberStyles.AllowHexSpecifier);

            byte[] floatVals = BitConverter.GetBytes(num);
            float f = BitConverter.ToSingle(floatVals, 0);
            //textBox3.Text = f.ToString();
            return f;
        }

        private int Hextoint(string mes1)
        {
            int value = Convert.ToInt16(mes1,16);

            return value;
        }
        
        private void MessageSap(string tt)
        {
            
            string[] mes = tt.Split('\t','\r');
            
            switch (mes[0])
            {
                case "A0":

                    string HAccX = mes[1] + mes[2];
                    string HAccY = mes[3] + mes[4];
                    string HAccZ = mes[5] + mes[6]; ;
                    AcX = (float)Hextoint(HAccX) / 16384;
                    AcY = (float)Hextoint(HAccY) / 16384;
                    AcZ = (float)Hextoint(HAccZ) / 16384;
                    textBox4.Text = textBox4.Text = String.Format("{0:0.00}", AcX); ;
                    textBox5.Text = textBox5.Text = String.Format("{0:0.00}", AcY); ;
                    textBox6.Text = textBox6.Text = String.Format("{0:0.00}", AcZ); ;
                    this.chart2.Series["Side G"].Points.Add(AcX);
                    linetxt = AcX.ToString() + '\t' + AcX.ToString() + '\t' + AcX.ToString() + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + "\r\n";
                    break;
                case "B0":
                    string HYaw = mes[4] + mes[3] + mes[2] + mes[1];
                    Yaw = (Hextofloat(HYaw) * (float)180 / (float)3.14);
                    textBox7.Text = String.Format("{0:0.00}", Yaw);
                    linetxt = "-\t-\t-\t" + Yaw.ToString() + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + "\r\n";
                    break;
                case "B1":
                    string HPitch = mes[4] + mes[3] + mes[2] + mes[1];
                    Pitch = Hextofloat(HPitch) * (float)180 / (float)3.14;
                    textBox8.Text = textBox8.Text = String.Format("{0:0.00}", Pitch);
                    linetxt = "-\t-\t-\t-\t" + Pitch.ToString() + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + "\r\n";
                    break;
                case "B2":
                    string HRoll = mes[4] + mes[3] + mes[2] + mes[1];
                    Roll = Hextofloat(HRoll) * (float)180 / (float)3.14;
                    textBox9.Text = textBox9.Text = String.Format("{0:0.00}", Roll);
                    linetxt = "-\t-\t-\t-\t-\t" + Roll.ToString() + '\t' + '-' + '\t' + '-' + '\t' + '-' + '\t' + '-' + "\r\n";
                    break;
                case "C0":
                    string HLat = tt[2].ToString() + tt[3].ToString() + tt[4].ToString() + tt[5].ToString() + tt[6].ToString() + tt[7].ToString() + tt[8].ToString() + tt[9].ToString();
                   // Lat = Hextofloat(HLat);
                    textBox2.Text = Lat.ToString();
                    linetxt = "\r\n";
                    break;
                case "C1":
                    string HLong = tt[2].ToString() + tt[3].ToString() + tt[4].ToString() + tt[5].ToString() + tt[6].ToString() + tt[7].ToString() + tt[8].ToString() + tt[9].ToString();
                   // Long = Hextofloat(HLong);
                    textBox3.Text = Long.ToString();
                    linetxt = "\r\n";
                    break;
                case "E0":
                    string fEngine = mes[1] + mes[2];
                    string fSpeed = mes[3] + mes[4];
                    string fThrottle = mes[5] + mes[6];
                    textBox1.AppendText(fEngine);
                    textBox14.AppendText(fSpeed);
                    textBox15.AppendText(fThrottle);
                    break;
                case "E1":
                    string fTime = mes[1] + mes[2];
                    //Time=fTime.ToString;
                    textBox16.AppendText(fTime);
                    linetxt = "\r\n";
                    break;
                case "F0":
                    string HFR = mes[1] + mes[2];
                    FR = Hextoint(HFR);
                    Modelabsorber2(FR);
                    textBox11.Text = FR.ToString();
                    CFR = 1;
                    linetxt = "-\t-\t-\t-\t-\t-\t" + FR.ToString() + '-' + '-' + '-' + "\r\n";
                    break;
                case "F5":
                    string HFL = mes[1] + mes[2];
                    FL = Hextoint(HFL);
                    Modelabsorber1(FL);
                    textBox10.Text = FL.ToString();
                    CFL = 1;
                    linetxt = "-\t-\t-\t-\t-\t-\t-\t" + FL.ToString() + '\t' + '-' + '\t' + '-' + "\r\n";
                    break;
                case "FA":
                    string HBR = mes[1] + mes[2];
                    BR = Hextoint(HBR);
                    Modelabsorber4(BR);
                    textBox13.Text = BR.ToString();
                    CBR = 1;
                    linetxt = "-\t-\t-\t-\t-\t-\t-\t-\t" + BR.ToString() + '\t' + '-' + "\r\n";
                    break;
                case "FF":
                    string HBL = mes[1] + mes[2];
                    BL = Hextoint(HBL);
                    Modelabsorber3(BL);
                    textBox12.Text = BL.ToString();
                    CBL = 1;
                    linetxt = "-\t-\t-\t-\t-\t-\t-\t-\t-\t" + BL.ToString() + "\r\n";
                    break;
                default: break;


            }
            if (CFR + CFL + CBR + CBL == 4)
            {
                this.chart1.Series["Front Right"].Points.Add(FR, yax);
                this.chart1.Series["Front Left"].Points.Add(FL, yax);
                this.chart1.Series["Back Right"].Points.Add(BR, yax);
                this.chart1.Series["Back Left"].Points.Add(BL, yax);
                yax++;
                CFR = 0;  CFL = 0; CBR = 0; CBL = 0;
            }
            //Create the file for real.
            using (System.IO.StreamWriter fileReal =
            new System.IO.StreamWriter(@textBox18.Text+"Real", true))
            {
                fileReal.WriteLine(linetxt);
            }
            linetxt = "";


        }
    }
}


