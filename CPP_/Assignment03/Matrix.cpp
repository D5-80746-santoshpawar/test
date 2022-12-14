#include <iostream>
using namespace std;
class Matrix
{
private:
    int row;
    int col;
    int **arr;

public:
    Matrix()
    {
        cout << "Enter the row" << endl;
        cin >> row;
        cout << "Enter the coloumn" << endl;
        cin >> col;
        this->arr = new int *[this->row];
        for (int i = 0; i < this->row; i++)
        {
            arr[i] = new int[this->col];
        }
    }
    Matrix(int row, int col)
    {
        this->arr = new int *[this->row];
        for (int i = 0; i < this->row; i++)
        {
            arr[i] = new int[this->col];
        }
    }
    void AcceptMatrix()
    {
        cout << "Enter the matrix" << endl;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                cout << "arr[" << i <<"]"
                     << "[" << j <<"]" << endl;
                cin >> arr[i][j];
            }
        }
    }
    void ShowMatrix()
    {
        cout << "Your Matrix :" << endl;
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                cout << "arr[" << i <<"]"
                     << "[" << j <<"] : " << arr[i][j] << endl;
            }
        }
    }
    Matrix AddMatrix(Matrix *mat)
    {
        if (this->row == this->col)
        {
            cout << "Enter value of row & coloumn Same" << endl;
        }
        else
        {
            Matrix *result = new Matrix[row][col];
            for (int i = 0; i < this->row; i++)
            {
                for (int j = 0; j < this->col; j++)
                {
                    result->arr[i][j] = this->arr[i][j] + mat->arr[i][j];
                }
            }
             return *result;
        }
       
    }
    Matrix SubMatrix(Matrix *mat)
    {
        if (this->row == this->col)
        {
            cout << "Enter value of row & coloumn Same" << endl;
        }
        else
        {
            Matrix  *result = new Matrix[row][col];
            for (int i = 0; i < this->row; i++)
            {
                for (int j = 0; j < this->col; j++)
                {
                    result->arr[i][j] = this->arr[i][j] - mat->arr[i][j];
                }
            }
              return *result;
        }
       
    }
    Matrix MultMatrix(Matrix *mat)
    {
        Matrix *result= new Matrix[row][col];
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->col; j++)
            {
                for (int k = 0; i < this->col; k++)
                {
                    result->arr[i][j] += arr[i][j] * mat->arr[k][j];
                }
            }
             return *result;
        }
       
    }
    Matrix Transpose(Matrix *Mat)
    {
        Matrix *result=new Matrix[row][col];
        for (int i = 0; i < this->row; i++)
        {
            for (int j = i + 1; j < this->col; j++)
            {
                result = swap(this->arr[i][j],Mat->arr[j][i]);
            }
        }
        return *result;
    }

    ~Matrix()
    {
        for (size_t i = 0; i <row; i++)
        {
            delete[] arr[i];
        }
        delete[] arr;
    }
};
enum MyEnum
{
    Accepmatrix = 1,
    Addmatrix,
    PrintMatrix,
    Submatrix,
    Multmatrix,
    Transmatrix,
    Default,
    End,

};
int main()
{
    Matrix *m1, *m2;
    int value, choice;
    while (true)
    {
        cout << "1.Accept Matrix" << endl;
        cout << "2.Addition Matrix" << endl;
        cout << "3.Print Matrix" << endl;
        cout << "4.Subtraction Matrix" << endl;
        cout << "5.Multiplication Matrix" << endl;
        cout << "6.Transpose Matrix" << endl;
        cout << "Enter choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case Accepmatrix:
            cout << "Enter the First Matrix" << endl;
            m1->AcceptMatrix();
            cout << "Enter the Second Matrix" << endl;
            m2->AcceptMatrix();
            break;
        case Addmatrix:
            m1->AddMatrix(m2);
            break;
        case PrintMatrix:
            cout << "Your First Matrix " << endl;
            m1->ShowMatrix();
            cout << "Your Second Matrix " << endl;
            m2->ShowMatrix();
            break;
        case Submatrix:
            m1->SubMatrix(m2);
            break;
        case Multmatrix:
            m1->MultMatrix(m2);
            break;
        case Transmatrix:
            m1->Transpose(m2);
            break;
        case Default:
            cout << "Your choice is Invalid" << endl;
            break;
        case End:
            cout << "You are Exiting " << endl;
            return 0;
        }
    }

    return 0;
}