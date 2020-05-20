#include <iostream>
#include <algorithm>
#include <string>
#include <random>
#include <ctime>

#include"sequence.h"
#include"array.h"
#include"list.h"
#include"d_matrix.h"
#include"linked_linst.h"

using namespace std;

struct Student
{
    string name;
    int age;
    Student(string name, int age)
    {
        this->name=name;
        this->age=age;
    }
    Student()
    {
        this->name="";
        this->age=0;
    }

    void Student_Output()
    {
       cout<<this->name<<this->age;
    }
     friend ostream& operator<<(ostream& os, const Student& st);

};

ostream& operator<<(ostream& os, const Student& st)
{
    os<<st.name<<" "<<st.age<<"\n";
}

template<class>

void arr_rand(int*arr,int size)
{
    for(int i=0;i<size;i++)
        arr[i]=rand();
}

void print_arr(int*arr,int size)
{
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

void print_ob(Sequence<int>* ob)
{
    int size=ob->get_length();

    for(int i=0;i<size;i++)
    {
        cout<<i<<": "<<ob->get_index(i)<<"\n";
    }
    cout<<endl;
}


int main()
{
    setlocale(LC_ALL,"RUS");
    srand((time(0)));

  int size=0;
    /*cout<<"Размер\n";
    cin>>size;
   // int n=((size*(size-1))/2+size);
    int a[size];
    for (int i=0; i<size; i++){
        cin>>a[i];
    }
     /*Matrix<int> b(a, size);
     b.Matrix_Output();
     Matrix<int> d(b);
     d.Matrix_Output();
     D_Array<int> b(a, size);*/
  Student masha("Maria", 18);
  Student ilyua("Ilya", 28);
  Student kostya("Konstantin", 22);
  Student sasha("Alexandra", 28);
  Student ilyusha("Ilya", 18);
  std::vector<Student> a{masha, ilyua, kostya, sasha, ilyusha};
  auto newEnd = std::remove_if(a.begin(), a.end(), [](Student x)->bool{
          if(x.name=="Ilya")
              return true;
          else
              return false;
});
  a.erase(newEnd, a.end());
  for(Student x : a){
      std::cout<<x<<"\n";
  }
  /*Student a[5]={masha, ilyua, kostya, sasha, ilyusha};
  D_Array<Student> b(a, 5);
  b.remove_by_function([](Student x)->bool{
      if(x.name=="Ilya")
          return true;
      else
          return false;
  });
  b.Array_Output();
     /*b.remove_by_function([](int x)->bool{
            if(x>5)
                return true;
            else
                return false;
        });*/


      /* My_Linked_List<int> c(a, n);
     My_Linked_List<int>*f=c.get_subsequence(2, 4);
     f->List_Output(); */

/*    int type=10;
    int n=0;
    int function=0;
    int question=0;
    while(type!=0)
    {
        cout<<"\nДля завершения программы нажмите 0\nДля работы с целыми числами введите 1\nДля работы с десятичными числами введите 2\n";
        cin>>type;
        if(type==0)
            continue;
        cout<<"Введите размер матрицы\n";
        cin>>n;
        if(n==0)
        {
            cout<<"Неверный размер матрицы\n";
            continue;
        }
        int size=((n*(n-1))/2+n);
        if (type==1)
        {
            int arr1[size];
            cout<<"Введите матрицу\n";
            for(int i=0; i<size; ++i)
            {
                cin>>arr1[i];
            }
            cout<<"Для создания матрицы через список списков введите 0\nДля создания матрицы через список массивов введите 1\nДля создания матрицы через массив списков введите 2\nДля создания матрицы через массив массивов введите 3\n";
            cin>>question;
            Matrix<int> first(arr1, n, question);
            cout<<"Для сложения матриц введите 1\nДля умножения матрицы на число введите 2\nДля нахождения нормы матрицы введите 3\n";
            cin>>function;
            if (function==1)
            {
                int arr2[size];
                cout<<"Введите вторую матрицу\n";
                for(int i=0; i<size; ++i)
                {
                    cin>>arr2[i];
                }
                Matrix<int> second(arr2, n, question);
                Matrix<int>*third=first.Matrix_Sum(second);
                third->Matrix_Output();
            }
            if (function==2)
            {
                int scalar;
                cout<<"Введите множитель\n";
                cin>>scalar;
                Matrix<int>*third=first.Matrix_Multi(scalar);
                third->Matrix_Output();
            }
            if (function==3)
            {
                cout<<first.Matrix_Norm();
            }
        }
        else
        {
            if (type==2)
            {
                float arr1[size];
                cout<<"Введите матрицу\n";
                for(int i=0; i<size; ++i)
                {
                    cin>>arr1[i];
                }
                cout<<"Для создания матрицы через список списков введите 0\nДля создания матрицы через список массивов введите 1\nДля создания матрицы через массив списков введите 2\nДля создания матрицы через массив массивов введите 3\n";
                cin>>question;
                Matrix<float> first(arr1, n, question);
                cout<<"Для сложения матриц введите 1\nДля умножения матрицы на число введите 2\nДля нахождения нормы матрицы введите 3\n";
                cin>>function;
                if (function==1)
                {
                    float arr2[size];
                    cout<<"Введите вторую матрицу\n";
                    for(int i=0; i<size; ++i)
                    {
                        cin>>arr2[i];
                    }
                    Matrix<float> second(arr2, n, question);
                    Matrix<float>*third=first.Matrix_Sum(second);
                    third->Matrix_Output();
                }
                if (function==2)
                {
                    float scalar;
                    cout<<"Введите множитель\n";
                    cin>>scalar;
                    Matrix<float>*third=first.Matrix_Multi(scalar);
                    third->Matrix_Output();
                }
                if (function==3)
                {
                    cout<<first.Matrix_Norm();
                }
            }
        }
    }

    //TEST ARRAY
/*    int arr[5];
    cout<<endl;
    arr_rand(arr,5);
    print_arr(arr,5);
    cout<<endl;
    cout<<endl;

    D_Array<int> a(arr,5);
    print_ob(&a);
    D_Array<int>* b=a.get_subsequence(2,4);
    print_ob(b);
    D_Array<int>*c=b->concat(&a);
    print_ob(c);
    c->append(5);
    c->prepend(8);
    print_ob(c);*/

    //TEST MATRIX_1
/*    int arr11[10]={2,2,3,3,1,1,1,1,1,1};
    int arr2[10]={1,1,1,1,1,1,5,6,7,8};

    Matrix<int> d(arr11,4,type);
    d.Matrix_Output();
    Matrix<int> e(arr2,4,type);
    e.Matrix_Output();
    Matrix<int>*f= e.Matrix_Sum(d);
    f->Matrix_Output();
    f=f->Matrix_Multi(5);
    f->Matrix_Output();
    cout<<f->Matrix_Norm();*/

    //TEST MATRIX_2
/*    float arr1[10]={2,2.2,3,3,1,1,1,1,1,1};
    float arr2[10]={1,1.3,1,1,1,1,5,6,7,8};

    Matrix<float> d(arr1,4,type);
    d.Matrix_Output();
    Matrix<float> e(arr2,4,type);
    e.Matrix_Output();
    Matrix<float>*f= e.Matrix_Sum(d);
    f->Matrix_Output();
    f=f->Matrix_Multi(5);
    f->Matrix_Output();
    cout<<f->Matrix_Norm();*/


    return 0;
}
