//Shofia Atika Nadhira
//123210016
//Tugas PTB
#include <bits/stdc++.h>
using namespace std;

struct tree
{
    int data;
    tree* left;
    tree* right;
};

tree* BuatNode(int data){
    tree* newTree = new tree();
    if (!newTree){
        cout << "Penyimpanan error!"<<endl;
        return NULL;
    }

    newTree->data = data;
    newTree->left = newTree->left = NULL;
    return newTree;
}

void SortTree(struct tree* root, int arr[], int &k){
    if (root != NULL){
        SortTree(root->left, arr, k);
        arr[k++] = root->data;
        SortTree(root->right, arr, k);
    }
    
}

tree* BangunNode(tree* root, int data){
    if ( root == NULL){
        return BuatNode(data);
    }

    if (data < root->data)
    {
        root->left = BangunNode(root->left, data);
    }else {
        root->right = BangunNode(root->right, data);
    }

    return root;
    
}
void HapusNode(struct tree* root, struct tree* del_node){
    queue<tree*> q;
    q.push(root);

    struct tree* temp;
    while (!q.empty())
    {
        temp =q.front();
        q.pop();

        if (temp == del_node){
            temp == NULL;
            delete (del_node);
            return;
        }

        if ( temp->right ){
            if ( temp->right == del_node ){
                temp->right = NULL;
                delete (del_node);
            }
            else
            {
                q.push(temp->right);
            }            
        }

        if ( temp->left ){
            if ( temp->left == del_node ){
                temp->left = NULL;
                delete(del_node);
            }
            else
            {
                q.push(temp->left);
            }
        }
    }    
}

tree* Hapus(struct tree* root, int hapus){
    if ( root == NULL ){
        return NULL;
    }

    if ( root->left == NULL && root->right == NULL){
        if ( root->data == hapus ){
            return NULL;
        }else
        {
            return root;
        }
        
    }

    queue<struct tree*> q;
    q.push(root);

    struct tree* temp;
    struct tree* hapus_node = NULL;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        if (temp->data == hapus){
            hapus_node = temp;
        }

        if (temp->left){
            q.push(temp->left);
        }

        if ( temp->right ){
            q.push(temp->right);
        }
    }
    if ( hapus_node != NULL ){
        int x = temp->data;
        HapusNode(root, temp);
        hapus_node->data = x;
    }
    return root;
}

void PreOrder(struct tree* root){
    if (root != NULL){
        cout << root->data << " ";
        PreOrder(root->left);
        PreOrder(root->right);
    }
}

void InOrder(struct tree* root){
    if (root != NULL){
        InOrder(root->left);
        cout << root->data << " ";
        InOrder(root->right);
    }
}

void PostOrder(struct tree* root){
    if (root != NULL){
        PostOrder(root->left);
        PostOrder(root->right);
        cout << root->data << " ";
    }
}
void cetak(struct tree* root){
    cout<<"\nPre-order : ";
	PreOrder(root);
    cout<<endl;
	
    cout<<"\nIn-order : ";
	InOrder(root);
    cout<<endl;

	cout<<"\nPost-order: ";
	PostOrder(root);
    cout<<endl;
}

int MinValue(struct tree* root){
    struct tree* temp = root;

    while (temp->left != NULL)
    {
        /* code */
        temp = temp->left;
    }
    return (temp->data);    
}

int testError(int arr[], int index){
    if ( arr[index-1] == 0){
        throw "You Must Input In Declare Index!";
    }
    return arr[index-1];
}

int main(){
    int banyakData, BanyakElementHapus, input; 
    int hapusElement[20];
    int SortElement[20];
    int pilihan;
    tree* root = new tree();
    root = NULL;


    char menu;

    int arr[20];
    do
    {
        /* Menu  */
        system("clear");
        cout<<"----------MENU----------";
        cout<<"\n1. Sisip Node";
        cout<<"\n2. Hapus Node";
        cout<<"\n3. Cetak Node";
        cout<<"\n4. Nilai Minimum";
        cout<<"\n5. Nilai Maximum";
        cout <<"\nMasukan Pilihan : ";cin >>pilihan;
        cout <<endl;
        int k = 0;
        int j = 0;
        switch (pilihan)
        {
        case 1:
            /* Membuat Node untuk memabangun Tree Transversal */
            system("clear");
            cout <<"----------SISIP NODE----------"<<endl;
            cout <<"\nMasukan Banyak Data yang akan Dimasukan : "; cin >> banyakData;
            for (int i = 0; i < banyakData; i++)
            {
                cout <<"Masukan Element Ke - " << i+1 << " ";cin >> arr[i];
                root = BangunNode(root, arr[i]);
            }
            break;
        case 2:
            /*Menghapus Node Sesuai dengan element yang di input*/
            system("clear");
            cout <<"----------HAPUS NODE----------"<<endl;
            cout <<"\nMasukan Banyak Data yang akan DiHapus : "; cin >> BanyakElementHapus;
            for (int i = 0; i < BanyakElementHapus; i++)
            {
                cout <<"Masukan Element Ke - " << i+1 << " ";cin >> hapusElement[i];
                root = Hapus(root, hapusElement[i]);

                /*Menghapus Element di array agar memudahkan untuk mencari maximum value sesuai index*/
                for(int j = 0; j < banyakData; j++){
                    if (arr[j] == hapusElement[i]){
                        arr[j] = 0;
                        break;
                    }
                }
            }
            break;
        case 3:
            /* Mencetak Node Secara Pre-In-Post Order */
            system("clear");
            cout <<"----------CETAK NODE----------"<<endl;
            cetak(root);
            cout << endl;
            
            break;
        case 4:
            /* Mengeluarkan Minimum Value */
            system("clear");
            cout <<"----------MINIMUM VALUE----------"<<endl;

            cout << "Minimum Value From This Tree Is : " << MinValue(root) <<endl;
            break;
        case 5:
            /* Mengeluarkan Maximum Value sesuai Index yang di input */
            system("clear");
            cout <<"----------MAXIMUM VALUE----------"<<endl;
            
            /*Try catch untuk menangkap kesalahan inputan apabila
            telah melampaui index atau Out Of Range*/
            try
            {
                /* code */
                for (int i = 0; i < banyakData ; i++)
                {
                    SortElement[i] = arr[i];
                }
                /*Function Sort untuk mengurutkan array sesuai desc*/
                sort(SortElement, SortElement + banyakData, greater<int>());

                cout <<"Input Index Nilai Maximum Yang Ingin Dicari : "; cin >> input;
                int result = testError(SortElement, input);
                cout <<"\nNilai Maximum Index Ke - " << input << " = " << result;
                cout << endl;

            }
            catch(const char* e)
            {
                cerr << e <<endl;
            }        
            
            break;
        }
        system("clear");
        cout << "\nApakah anda ingin mengulangi program ini ? (y/n) : ";cin >> menu;
        cout <<endl;
    } while (menu == 'y' || menu == 'Y');
    
}