#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

class Node {
private:
	string value;
	int kode;
	vector<Node*> childs;
public:
	Node(string _value = "", int kd = 1) {
		value = _value;
		kode = kd;
	}

	void setValue(string _value = "", int kd = 1) {
		value = _value;
		kode = kd;
	}

	string getValue() {
		return value;
	}

	void addChild(Node* child) {
		childs.push_back(child);
	}
	Node* getChild(int index) {
		return childs[index];
	}

	int getcode() {
		return kode;
	}
};

class Tree {
private:
	Node* root;
	Node* current;
public:
	Tree() {
		root = NULL;
		current = NULL;
	}
	void setRoot(string _root, int x) {
		root = new Node(_root, x);
		current = root;
	}

	void edit_root(string n, int x) {
		current = root;
		current->setValue(n, x);
	}

	void edit_child(string n, int x) {
		current->setValue(n, x);
	}

	Node* getRoot() {
		return root;
	}

	void display(int index) {
		cout << current->getValue() << endl;
	}

	void setCurrent(int index) {
		Node* tmp = current;
		cout << tmp->getValue() << endl;
		current = current->getChild(index);
	}

	void addCurrentChild(string n, int x) {
		Node* tmp = new Node(n, x);
		current->addChild(tmp);
	}

	string getValue() {
		return current->getValue();
	}

	void resetCur() {
		current = root;
	}

	int getcode() {
		return current->getcode();
	}
};


class Cgame {
private:
	Tree a;
public:
	void question() {
		//root
		a.setRoot("Semalam kamu tidur dengan sangat pulas, namun tiba - tiba saat kamu terbangun, kamu berada di ruangan yang sangat gelap.Namun kamu melihat ada 2 pintu yang bercahaya di kanan dan di kiri dan tengah.Pintu manakah yang akan kamu pilih ?\n0. kiri\n1.tengah\n2. kanan", 1);
		a.addCurrentChild("Kamu memasuki pintu kiri dan berjalan hingga 6 jam lamanya. Lalu kembali lagi melihat 3 pintu yang bercahaya.", 0);
		a.addCurrentChild("Kamu memasuki pintu tengah dan kamu merasakan ada sesuatu yang aneh, \nDi ruangan tersebut terdapat banyak boneka yang sangat menyeramkan namun kamu berusaha mengabaikannya dan tetap berjalan, lalu jalan tersebut terpecah menjadi 2, naik ke atas menggunakan tangga atau turun ke bawah menggunakan tali? \n0. tali\n1.tangga ", 1);
		a.addCurrentChild("Kamu memasuki pintu kanan dan suasana menjadi sedikit menyeramkan\nDi ruangan ini, kamu melihat banyak sekali kalelawar yang tidur. Kamu terus berjalan hingga menemukan Seseorang yang sangat aneh sedang bermain gitar. Dia memintamu sedikit makanan yang kamu punya untuk ia makan. Apakah kamu akan memberikan makanan tersebut?\n0. iya\n1. taidak", 1);

		//cabang tengah
		//2
		a.setCurrent(1);
		a.addCurrentChild("Tali yang kamu pegang ini ternyata ular yang sangat kuat dan berbisa.Dia mengigit kepalamu hingga kamu tak sadarkan diri lagi.", 0);
		a.addCurrentChild("Perjalanan diteruskan, dan seketika cuaca menjadi sangat panas.Dan kamu bingung mau buang jaket yang sedang dipakai atau tidak.\nPerjalanan diteruskan, dan seketika cuaca menjadi sangat panas. Dan kamu bingung mau buang jaket yang sedang dipakai atau tidak.\n0.tidak \n1. buang jaket", 1);
		//3
		a.setCurrent(1);
		a.addCurrentChild("Tiba-tiba Laper, untung ga lepas jaket, ada makanannya cuy di kantong.\nSetelah menempuh perjalanan yang melelahkan, lagi-lagi jalan terpecah menjadi 3, Kanan, kiri dan tengah jalan mana yang ingin kamu pilih?\n0.kiri\n1.tengah\n2.kanan", 1);
		a.addCurrentChild("Kamu merasa sangat kelaparan karena menempuh perjalanan yang begitu berat. Namun kamu mengingat sesuatu, semua makanan darurat yang kamu miliki ada di kantong jaket tadi. Akhirnya kamu mati kelaparan.", 0);
		//4
		a.setCurrent(0);
		a.addCurrentChild("Ternyata jalan yang kamu ambil ini terlihat sangat aman dan tidak ada yang mencurigakan.\nSetelah berjalan 1 jam lamanya, Kamu melihat seekor sapi. Lalu muncul dibenakmu 2 pilihan, Dibunuh lalu dimasak untuk dimakan, atau ditunggangi sebagai kendaraan.\n0.Dibunuh lalu dimasak untuk dimakan\n1.ditunggangi sebagai kendaraan", 1);
		a.addCurrentChild("Yah, mati kemakan beruang ", 0);
		a.addCurrentChild("Jalan yang kamu ambil ini terlihat sedikit menyeramkan namun tidak terjadi apa-apa\nSetelah berjalan 1 jam lamanya, Tiba-tiba seorang malaikat terlihat sedang berdiri di tengah jalan dengan memberikan sebuah teka-teki, Punya bakat tapi malas, atau tidak punya bakat tapi rajin? Mana yang kamu pilih.\n0.tidak punya bakat tapi rajin\n1.Punya bakat tapi malas", 1);
		
		//cabang tengah ke kiri
		//5
		a.setCurrent(0);
		a.addCurrentChild("Ternyata kamu lupa kalau tidak membawa peralatan masak di tas, Sapinya udah terlanjur mati.Akhirnya kamu jalan 5 jam lamanya hingga mati karena kecapean", 0);
		a.addCurrentChild("Sapi tersebut terlihat sangat menyukaimu dan memperbolehkanmu untuk menungganginya, mantap dah dapet sapi tengah jalan, ga perlu capek jalan\nSetelah lama berjalan, kamu melihat sebuah kolam air yang terlihat jernih. Karena merasa haus, kamu bimbang mau minum air tersebut atau tidak.\n0.minum air tersebut\n1.tidak minum air tersebut", 1);
		//6
		a.setCurrent(1);
		a.addCurrentChild("Ternyata Air tersebut sangat bersih dan membuat kamu dan sapimu segar seketika\nPerjalanan diteruskan, dan lagi-lagi jalan terpisah menjadi 2, namun kali ini dengan diberikan tanda, ke kanan untuk jalan yang lebih cepat. Kamu mau pilih jalan yang kanan atau yang kiri?\n0.kanan\n1.kiri", 1);
		a.addCurrentChild("Karena terlalu ragu, Sapimu mati kehausan dan kamu juga merasa sangat haus hingga tidak kuat melanjutkan perjalanan lagi.", 0);
		//7
		a.setCurrent(0);
		a.addCurrentChild("Gitu dong ngikutin petunjuknya, memang yang kanan lebih cepat, kalau jalan yang kiri ada banyak kuntilanaknya.\nKamu sudah melihat pintu keluarnya, namun ada 3 pintu yang yang bercahaya.Pintu yang kiri terlihat banyak sekali bunga-bunga yang indah, Di Pintu tengah terdengar suara rantai dan semacam bunyi mesin. Sedangkan pintu kanan terdengar seperti suara orang yang memanggil-manggil namamu. Pintu mana yang kamu pilih?\n0.kiri\n1.tengah\n2.kanan", 1);
		a.addCurrentChild("Karena terlalu ragu, Sapimu mati kehausan dan kamu juga merasa sangat haus hingga tidak kuat melanjutkan perjalanan lagi.", 0);
		//8
		a.setCurrent(0);
		a.addCurrentChild("Ternyata pintu yang kiri memang berisikan bunga yang sangat indah, namun ternyata bunga itu merupakan bunga pemakan hewan dan manusia. Kamu terperangkap di dalam sana dan menjadi makanan bunga yang cantik itu.", 0);
		a.addCurrentChild("Selamat kamu telah menyelesaikan tantangan Temple of Death ", -1);
		a.addCurrentChild("Ternyata pintu yang kanan merupakan ruangan yang sangat kamu kenali, dan kalau tidak salah ruangan tersebut merupakan ruangan pertama dengan boneka-boneka yang seram yang memanggilmu tadi. Kamu menjadi gila dan terperangkap selamanya.", 0);

		//root
		a.resetCur();
		//2
		a.setCurrent(1);
		//3
		a.setCurrent(1);
		//4
		a.setCurrent(0);

		//cabang tengah ke kanan
		//9
		a.setCurrent(2);
		a.addCurrentChild("Malaikat puas dengan jawaban yang kamu pilih dan membiarkanmu lewat.\nPerjalanan dilanjutkan, lalu tiba-tiba matamu tertuju pada sebuah batu yang sangat besar dengan tulisan, “Hidup seperti Garry”. Lalu kamu mengabaikan tulisan tersebut dan meneruskan perjalanan hingga bertemu dengan seorang kakek-kakek yang sangat menyeramkan. Dia menawarkan untuk memberikan kepadamu kemampuan yang tidak dimiliki oleh orang normal. Yang pertama yaitu kemampuan untuk mengeluarkan cahaya dari bola mata atau kemampuan untuk melompat tinggi.\n0.kemampuan untuk mengeluarkan cahaya dari bola mata\n1.kemampuan untuk melompat tinggi", 1);
		a.addCurrentChild("Malaikat tersebut tidak puas dengan jawabanmu dan mencabut nyawamu.", 0);
		//10
		a.setCurrent(0);
		a.addCurrentChild("Tiba-tiba kamu masuk keruangan yang sangat gelap. Untung saja kamu memilih kemampuan untuk mengeluarkan cahaya.\nLalu kamu melanjutkan perjalanan, dan menemukan piring berisikan makanan yang terlihat sangat lezat dan terpikir dibenakmu untuk memakannya atau tidak.\n0.tidak\n1.makan.", 1);
		a.addCurrentChild("Kamu berada di ruangan yang sangat gelap, namun kamu tidak membawa senter. Akhirnya kamu yang panik karena takut ada kecoak, kamu tidak sengaja lompat di ruangan yang sempit tersebut hingga kepalamu bocor.", 0);
		//11
		a.setCurrent(0);
		a.addCurrentChild("Kamu merasa sangat kelaparan dan tidak bisa melanjutkan perjalanan dan mati kelaparan.", 0);
		a.addCurrentChild("Kamu makan dengan lahap dan Kembali segar.\n12.	Kamu melanjutkan perjalanan dan terhadang oleh sebuah dinding raksasa dengan tulisan “Barangsiapa yang suka mengabaikan sesuatu, ia akan mendapatkan balasannya.” Dan dinding itu meminta sebuah kalimat yang berisikan 3 kata. Muncul dibenakmu namun kamu sedikit ragu. Yang pertama “Hidup sebagai Larry” dan yang kedua “Hidup sebagai Garry” dam yang ketiga “Hidup sebagai Harry”. Mana yang kamu pilih?\n0.Hidup sebagai Larry\n1.Hidup sebagai harry.\n2.Hidup sebagai garry.", 1);
		//12
		a.setCurrent(1);
		a.addCurrentChild("Ternyata pintu raksasa tersebut terbuka namun ruangan tersebut sangat kamu kenali, dan kalau tidak salah ruangan tersebut merupakan ruangan pertama dengan boneka-boneka yang seram. Dan terpaksa kamu harus mengulangi semuanya lagi.", 0);
		a.addCurrentChild("Kamu memasuki pintu tersebut dan bertemu “Harry Styles”. Karena terlalu mengagumi dirinya sampai-sampai kamu tidak ingin pergi dari ruangan ini. Akhirnya kamu tidak Kembali ke dunia nyata lagi. ", 0);
		a.addCurrentChild("Selamat kamu telah menyelesaikan tantangan Temple of Death", -1);

		//root
		a.resetCur();

		//cabang kanan
		//2
		a.setCurrent(2);
		a.addCurrentChild("Karena kebaikanmu, kamu diberikan olehnya roti ajaib yang tidak akan pernah habis saat kamu makan.\nKamu melanjutkan perjalanan hingga kamu menemukan sebuah sepatu dan sebuah sandal. Tentu saja kamu tergiur melihat itu karena selama ini kamu berjalan dengan tidak menggunakan alas kaki. Mana yang kamu pilih.\n0.sandal\n1.sepatu", 1);
		a.addCurrentChild("Karena perjalanan yang sangat jauh. Makanan yang kamu punyapun habis dan kamu merasa sangat kelaparan hingga mati.", 0);
		//3
		a.setCurrent(0);
		a.addCurrentChild("Untung saja kamu memilih sandal, karena sepatu tersebut terdapat kalajengking di dalamnya dengan racun yang sangat mematikan.\nPerjalanan diteruskan hingga sampailah pada suatu jalan yang terpecah menjadi 3, kanan dan kiri dan ada 1 tangga yang mengarah ke atas. Jalan mana yang kamu pilih?\n0.kiri\n1.atas\n2.kanan", 1);
		a.addCurrentChild("Kamu merasakan ada sesuatu yang aneh di sepatumu dan kamu merasakan ada yang menyengat kakimu. Kamu menyadari bahwa sesuatu di dalam sepatumu itu ternyata seekor kalajengking yang sangat beracun. Akhirnya kamu mati setelah 2 jam menahan sakit tersebut.", 0);
		//4
		a.setCurrent(0);
		a.addCurrentChild("Kamu mengambil jalan kiri dan terus berjalan.Untuk saat ini tidak ada hal yang mencurigakan saya rasa jalan ini aman.\nSetelah sekian lama menempuh perjalanan, kamu melihat ada sepeda motor dan sepeda pancal BMX. Namun Ketika kamu sudah memilih, kamu tidak dapat memilih ulang karena barang yang tidak terpilih akan hancur seketika. Mana yang kamu pilih?\n0.BMX\n1.Sepeda Motor", 1);
		a.addCurrentChild("Kamu mengambil tangga tersebut dan sampai di suatu ruangan.Untuk saat ini tidak ada hal yang mencurigakan saya rasa jalan ini aman.\nSetelah sekian lama menempuh perjalanan, kamu melihat suatu lukisan yang sangat besar dan sangat indah, Lukisan tersebut memiliki tanggal ia diciptakan, terlihat disitu “030801”. Setelah selesai mengagumi lukisan tersebut ia dikejutkan dengan adanya seekor beruang raksasa di ujung ruangan yang dapat berbicara namun kakinya terikat oleh rantai. Beruang itu berkata “Nak, apakah kamu melihat rantai di kakiku ini? Apakah kamu mau menolongku?”. Kamu yang sedang ketakutan bingung antara ingin membantu beruang tersebut atau lari ketakutan.\n0.membantu\n1.lari", 1);
		a.addCurrentChild("Kamu mengambil jalan kanan dan menemukan sesuatu yang sangat besar dan mengerikan setelah menempuh 1 jam perjalanan. Binatang itu meminta nyawamu untuk dijadikan makan malam.", 0);
		
		//cabang kanan ke kiri
		//5
		a.setCurrent(0);
		a.addCurrentChild("Mantep banget cuy sepeda pancalnya. Gaspol ke tujuan selanjutnya.\nDalam perjalanan yang sangat melelahkan, Tiba-tiba kamu dikejutkan dengan adanya air terjun yang sangat indah. Dan tiba-tiba kamu merasa haus, namun kamu bimbang dengan kejernihan air terjun tersebut. Apakah kamu memilih untuk tetap minum atau duduk saja menikmati keindahan air terjun tersebut.\n0.minum\n1.tidak", 1);
		a.addCurrentChild("Kamu mengambil tangga tersebut dan sampai di suatu ruangan.Untuk saat ini tidak ada hal yang mencurigakan saya rasa jalan ini aman.", 0);
		//6
		a.setCurrent(0);
		a.addCurrentChild("Kamu kurang beruntung, Air yang kamu minum sangat beracun.", 0);
		a.addCurrentChild("Untung saja kamu tidak meminum air tersebut, karena sangat beracun\nDisaat kamu menikmati Air terjun tersebut, tiba-tiba datanglah Putri duyung yang sangat cantik dan mau membantumu untuk menemukan jalan keluar. Namun kamu begitu ragu dengan tawaran tersebut dan bingung mau menerima tawaran tersebut atau tidak.\n0.terima\n1.tidak", 1);
		//7
		a.setCurrent(1);
		a.addCurrentChild("Ternyata Putri Duyung tersebut memang berniat untuk membantumu. Akhirnya kamu menemukan Pintu Keluar\nNamun, saat kamu sudah di ujung pintu keluar, pintu tersebut tertutup dan tiba-tiba datanglah seorang malaikat dan memberimu pertanyaan. Jikalau kamu diberikan kesempatan untuk hidup lagi dan diberikan Harta yang sangat melimpah, apakah kamu mau menerimanya?\n0.tidak\n1.menerima", 1);
		a.addCurrentChild("Karena tidak menerima tawaran putri duyung tersebut, kamu tersesat dan selamanya terperangkap di dalam ruangan tersebut.", 0);
		//8
		a.setCurrent(0);
		a.addCurrentChild("Malaikat merasa puas dengan jawaban yang kamu berikan, Dia membukakan pintu tersebut dan seketika kamu bangun dari tidurmu.", -1);
		a.addCurrentChild("Malaikat tidak puas dengan jawaban yang kamu berikan, Malaikat tersebut merasa kamu kurang bersyukur dengan apa yang sudah kamu miliki saat ini dan dia membukakan pintu tersebut namun kamu melihat ruangan yang berisi banyak kalelawar. ", 0);

		//root
		a.resetCur();
		//2
		a.setCurrent(2);
		//3
		a.setCurrent(0);
		//4
		a.setCurrent(0);

		//cabang kanan ke tengah
		//9
		a.setCurrent(1);
		a.addCurrentChild("Kamu menjadi makan malam oleh beruang tersebut karena ingin menolong dan terlalu dekat dengannya.", 0);
		a.addCurrentChild("Kamu selamat karena sebenarnya beruang tersebut sangat kelaparan dan ingin memakanmu.\nSaat sedang lari ketakutan, tiba-tiba kamu melihat jalan tersebut terpecah menjadi 2 kanan dan kiri, kemanakah kamu akan berlari?\n0.kiri\n1.kanan", 1);
		//10
		a.setCurrent(1);
		a.addCurrentChild("Kamu jatuh kedalam jurang karena Left, is not the right way.", 0);
		a.addCurrentChild("Selamat, kamu memilih jalan yang benar karena right, is the right way.\nKarena merasa sangat Lelah, kamu memutuskan untuk beristirahat sejenak. Lalu kamu melihat sebuah Batu dengan bertuliskan “Sing for the Win”. Dan Kebetulan kamu hobi bernyanyi. Namun setelah semua yang kamu lalui, kamu ragu untuk mengikuti perintah batu tersebut dan terpikir, apakah aku harus bernyanyi atau tidak.\n0.bernyanyi\n1.tidak", 1);
		//11
		a.setCurrent(1);
		a.addCurrentChild("Batu tersebut tiba-tiba bersinar dan menunjukkan jalan menuju suatu ruangan.\nSetelah memasuki ruangan tersebut, kamu melihat Pintu yang bercahaya, namun kamu tidak bisa melewatinya karena terdapat Lukisan raksasa berbentuk puzzle yang memiliki potongan yang hilang. Dan potongan berjumlah sebanyak 6 buah dan semuanya angka. Kamu teringat sesuatu pada lukisan di ruangan sebelumnya namun kamu tidak ingat pasti. “Kalau tidak salah, saya rasa itu 080301 atau 030801 dan yang terakhir 080103.” Angka mana yang kamu pilih.\n0.030801\n1.080301\n2.080103", 1);
		a.addCurrentChild("Setelah beristirahat, kamu melihat sekililing ruangan tersebut namun tidak menemukan petunjuk. Kamu tersesat hingga menjadi gila.", 0);
		//12
		a.setCurrent(0);
		a.addCurrentChild("Lukisan tersebut tiba-tiba bersinar dan menghilang. Dan tidak ada lagi yang menghalangimu untuk menuju pintu tersebut. Akhirnya kamu keluar dengan selamat dan terbangun dari tidurmu yang menyeramkan.", -1);
		a.addCurrentChild("Lukisan tersebut menjadi semakin besar dan kamu terperangkap di dalam ruangan tersebut.", 0);
		a.addCurrentChild("ukisan tersebut meledak dan kamu terluka sangat parah hingga tak terselamatkan.", 0);
	}

	void display() {
		int x;
		a.resetCur();
		while (a.getcode() > 0) {
			cout << a.getValue() << endl;
			cin >> x;
			a.setCurrent(x);
			system("cls");
		}
		if (a.getcode() == 0) {
			cout << a.getValue() << endl;
			cout << "kamu kalah" << endl;
		}
		else if (a.getcode() == -1) {
			cout << a.getValue() << endl;
			cout << "kamu Menang" << endl;
		}
	}

	void edit(int i) {
		string x, d, b, c;
		if (i == 1) {
			a.resetCur();
			cout << "pertanyaan ke 1:" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban benar):" << endl;
			getline(cin, c);
			a.edit_root(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);
		}
		else if (i == 2) {
			a.resetCur();
			a.setCurrent(1);
			cout << "pertanyaan ke 2 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();

			a.setCurrent(2);
			cout << "pertanyaan ke 2 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

		}

		else if (i == 3) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			cout << "pertanyaan ke 3 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			cout << "pertanyaan ke 3 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
		}

		else if (i == 4) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			cout << "pertanyaan ke 4 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban benar):" << endl;
			getline(cin, c);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);

			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 4 (sisi kanan):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban salah):" << endl;
			getline(cin, c);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);
		}

		else if (i == 5) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 5 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 5 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(2);
			cout << "pertanyaan ke 9 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			cout << "pertanyaan ke 9 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
		}

		else if (i == 6) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			cout << "pertanyaan ke 6 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 6 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(2);
			a.setCurrent(0);
			cout << "pertanyaan ke 10 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(1);
			cout << "pertanyaan ke 10 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

		}

		else if (i == 7) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(0);
			cout << "pertanyaan ke 7 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			cout << "pertanyaan ke 7 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 11 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(1);
			cout << "pertanyaan ke 11 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);

		}

		else if (i == 8) {
			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(0);
			cout << "pertanyaan ke 8 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban salah):" << endl;
			getline(cin, c);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(0);
			cout << "pertanyaan ke 8 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban benar):" << endl;
			getline(cin, b);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b, 1);


			a.resetCur();
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			cout << "pertanyaan ke 12 (sisi kiri):" << endl;
			cin.ignore();
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban salah):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban benar):" << endl;
			getline(cin, c);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);
			a.resetCur();


			a.setCurrent(2);
			a.setCurrent(0);
			a.setCurrent(0);
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(1);
			a.setCurrent(0);
			cout << "pertanyaan ke 12 (sisi kanan):" << endl;
			getline(cin, x);
			cout << "pilihan jawaban ke 1(jawaban benar):" << endl;
			getline(cin, d);
			cout << "pilihan jawaban ke 2(jawaban salah):" << endl;
			getline(cin, b);
			cout << "pilihan jawaban ke 3(jawaban salah):" << endl;
			getline(cin, c);
			a.edit_child(x + "\n" + "0. " + d + "\n" + "1. " + b + "\n" + "2. " + c, 1);

		}

	}

	void run() {
		int main;
		int x = 0;
		int co = 0;
		question();
		a.resetCur();
		while (x == 0) {
			system("cls");
			cout << "~~~~TAMPLE OF DEATH~~~~" << endl;
			cout << "1.play" << endl;
			cout << "2.edit" << endl;
			cout << "3.exit" << endl;
			cout << "CHOICE: "; cin >> main;
			if (main == 1) {
				if (co == 0) {
					system("cls");
				}
				co++;
				display();
			}
			else if (main == 2) {
				int x;
				system("cls");
				cout << "~~~~TAMPLE OF DEATH~~~~" << endl;
				cout << "1. level 1 (root)" << endl;
				cout << "2. Level 2" << endl;
				cout << "3. Level 3" << endl;
				cout << "4. Level 4" << endl;
				cout << "5. Level 5" << endl;
				cout << "6. Level 6" << endl;
				cout << "7. Level 7" << endl;
				cout << "8. Level 8" << endl;
				cout << "0. Exit" << endl;
				cout << "CHOICE: "; cin >> x;
				edit(x);
			}
			else if (main == 3) {
				cout << "~~~~THANKYOU~~~~" << endl;
				x = 1;
			}
			co = 0;
			system("pause");
		}
	}
};

void main() {
	Cgame x;
	x.run();
}