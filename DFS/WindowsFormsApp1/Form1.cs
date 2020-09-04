using System;
using System.Collections;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //ödevin nasıl yapılacağını araştırırken arama algoritmalarını buldum ve nasıl yapılacağını öğrendim. DFS(derin öncelikli arama)'nın soruya uygun olduğunu görüp bu algoritmayı kullandım ve düğümleri bu şekilde gezdim.
            int sayac = 0;
            string pathData1 = "c:\\users\\dream\\Desktop\\data1.txt", pathData2 = "c:\\users\\dream\\Desktop\\data2.txt";  //okuyacağımız txt dosyalarının yollarını belirliyoruz
            string icerikData1 = File.ReadAllText(pathData1, Encoding.UTF8);    //dosyadaki tüm texti okuyoruz
            string icerikData2 = File.ReadAllText(pathData2, Encoding.UTF8);    //dosyadaki tüm texti okuyoruz
            icerikData1 = icerikData1.Replace(" ", ""); //düğüm değerlerini yazdığımız txt dosyasında değerler boşluk ile ayrıldığından boşlukları siliyoruz
            icerikData2 = icerikData2.Replace(Environment.NewLine, "");  //düğüm ilişkilerini yüklediğimiz dosyadaki her düğümün ilişkilerinden sonra gelen line'ları kaldırıyoruz
            char[] deger = new char[icerikData1.Length];    //deger dizimizi, değerlerimizi yüklediğimiz txt'den aldığımız stringin boyutunda başlatıyoruz
            char[,] baglanti = new char[icerikData1.Length, icerikData1.Length];    //baglanti dizimizi, ilişkileri yüklediğimiz txt'den aldığımız stringin boyutunda başlatıyoruz
            for (int i = 0; i < icerikData1.Length; i++)    //deger dizimize degerleri yüklüyoruz
            {
                deger[i] = icerikData1.ElementAt(i);
            }
            for (int i = 0; i < icerikData1.Length; i++)    //baglanti dizimize baglantilarimizi yüklüyoruz
            {
                for (int j = 0; j < icerikData1.Length; j++)
                {
                    baglanti[i, j] = icerikData2.ElementAt(sayac);
                    sayac++;
                }
            }
            int[] degerInt = Array.ConvertAll(deger, c => (int)Char.GetNumericValue(c));    //deger dizimizdeki tüm değerleri int tipine cast ediyoruz(daha sonra değerleri her kullandığımızda tekrar cast etmemek için)
            yazdir(degerInt, baglanti); //değerlerimizi ve bağlantılarımızı hesaplanması ve yazdırılması için fonksiyonumuza gönderiyoruz
        }
        public void yazdir(int[] deger, char[,] baglanti)   //puan hesaplaması ve yazdırma yapan fonksiyon
        {
            LinkedList<int>[] yakinlik; //düğümlerin yakınlık ilişkilerini tutacağımız LinkedList
            int puan = 0; //puanımızı hesaplamak için int tipinde puan değişkeni
            for (int i = 0; i < deger.Length; i++)  //düğümlerimizin sayısı kadar dönecek bir döngü oluşturuyoruz, tüm nodeların puanını tek tek hesaplayacağız
            {
                textBox1.Text += i+1 + " nolu dugumun puani: "; //textbox'umuzun başlangıcını ödevde istenen şekilde başlatıyoruz(i+1 yapıyoruz çünkü dizi indexi ve for döngüsü 0'dan başlıyor
                int temp = i;   //stack için kullanacağımız, hesaplayacağımız node indexinden başlayan bir değişkene ihtiyacımız var bu neden ile temp değişkeni oluşturup bu değişkene i'yi atıyoruz
                yakinlik = new LinkedList<int>[deger.Length];   //yakınlık listemizi başlatıyoruz(null hatası almamak için)
                for (int j = 0; j < yakinlik.Length; j++)
            {
                yakinlik[j] = new LinkedList<int>();    //yakınlık listemizin her bir elemanını yeni bir liste ile başlatıyoruz
            }
                
            for (int j = i; j < deger.Length; j++)  //bu döngüde yakınlık listemize yakınlık ilişkilerini atıyoruz
            {
                for (int k = 0; k < deger.Length; k++)
                {
                    if (baglanti[j, k].Equals('1')){
                        yakinlik[j].AddLast(k);
                    }
                }
            }

                Boolean[] visited = new Boolean[deger.Length];  //başlangıçta hiçbir düğüm gezilmediğinden tüm değerleri false atıyoruz
                for (int j = 0; j < deger.Length; j++)
                {
                    visited[j] = (false);
                }
                
                Stack<int> stack = new Stack<int>();    //dfs(derin öncelikli arama) için stack oluşturuyoruz

                stack.Push(temp);   // gezmeye başlayacağımız düğümü stack'e pushluyoruz

                while (stack.Count > 0)
                {
                    
                    temp = stack.Peek();    //stack'in en üstündeki elemanı kaldırmadan çekiyoruz ve temp'e atıyoruz
                    stack.Pop();    //stack'in en üstündeki elemanı kaldırıyoruz

                    if (visited[temp] == false) //stackte aynı düğüm iki kere bulunabileceğinden, sadece daha önce gezilmeyen düğümün puanını alıyoruz ve aldıktan sonra düğümü gezildi olarak işaretliyoruz(daha sonra tekrar almamak için)
                    {
                        puan += deger[temp];
                        textBox1.Text +=  deger[temp] + "+";
                        visited[temp] = true;
                    }

                    // Get all adjacent vertices of the popped vertex s 
                    // If a adjacent has not been visited, then push it 
                    // to the stack. 
                    foreach (int v in yakinlik[temp])   //stackten aldığımız düğümün tüm yakınlık düğümlerini alıp, gezilmeyenleri stack'e geri pushluyoruz
                    {
                        if (!visited[v])
                            stack.Push(v);
                    }

                }
                int sonArti = textBox1.Text.LastIndexOf("+");   //en son eklenen '+'yı silmek için indexini belirliyoruz
                textBox1.Text = textBox1.Text.Remove(sonArti);  //indexini belirlediğimiz '+'yı texbox'ımızdan siliyoruz
                textBox1.Text += "= "+ puan + Environment.NewLine;  //textbox'ımıza "= " ekleyip puanı ekliyoruz, Environment.NewLine ekleyerek yeni satırdan başlamasını sağlıyoruz
                puan = 0;   //puanı bir sonraki düğüm için sıfırlıyoruz
            }
            
        }
    }
}