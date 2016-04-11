using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace Serial_port_test
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            string[] strPortNames=SerialPort.GetPortNames();
            foreach(string n in strPortNames)
            {
                comboBox1.Items.Add(n);
            }

            comboBox1.SelectedIndex = 0;
        }

       
        private void button1_Click(object sender, EventArgs e)
        {
            serialPort1.PortName = comboBox1.SelectedItem + "";
            serialPort1.Open();

        }
        int i = 0;
        private void serialPort1_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            //string a = serialPort1.ReadLine();
            //textBox1.Text = a;
            //textBox1.Text = "\n";
            textBox1.AppendText(serialPort1.ReadLine());
            textBox1.AppendText("\n");
            Console.WriteLine(i++);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            serialPort1.Close();
        }
    }
}
