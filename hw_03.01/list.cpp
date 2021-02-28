#include <iostream>

using namespace std;




struct cell                             
{
    int val;                             
    cell* next;
    cell* prev;                
};

struct List                              
{
    cell* first;
    cell* last;      
    int size;
    List()
    {
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    void push_back(int x)
    {
        size++;
        cell* temp = new cell;               //Выделение памяти под новый элемент структуры
        temp->next = nullptr;                   //Указываем, что изначально по следующему адресу пусто
        temp->val = x;                         //Записываем значение в структуру

        if (size != 1)                    //Если список не пуст
        {
            temp->prev = last;               //Указываем адрес на предыдущий элемент в соотв. поле
            last->next = temp;               //Указываем адрес следующего за хвостом элемента
            last = temp;                     //Меняем адрес хвоста
        }
        else //Если список пустой
        {
            temp->prev = NULL;               //Предыдущий элемент указывает в пустоту
            last = temp;
            first = temp;//Голова=Хвост=тот элемент, что сейчас добавили
        }
    }
    void push_front(int x)
    {
        size++;
        cell* temp = new cell;
        temp->prev = nullptr;
        temp->val = x;
        if (size != 1)
        {
            temp->next = first;
            first->prev = temp;
            first = temp;
        }
        else
        {
            temp->next = nullptr;
            last = temp;
            first = temp;
        }
    }
    void show()
    {
        cell* temp = first;                       //Временно указываем на адрес первого элемента
        for(int i = 0; i < size; i++)              //Пока не встретим пустое значение
        {
            cout << temp->val << " ";        //Выводим каждое считанное значение на экран
            temp = temp->next;             //Смена адреса на адрес следующего элемента
        }
        cout << endl;
    }
    void reverse()
    {
        cell* temp = first;
        cell* sw_buff;
        for (int i = 0; i < size; i++)
        {
            sw_buff = temp->next;
            temp->next = temp->prev;
            temp->prev = sw_buff;
            temp = temp->prev;
        }
        sw_buff = first;
        first = last;
        last = sw_buff;
    }
    void merge(List lst)
    {
        last->next = lst.first;
        lst.first->prev = last;
        last = lst.last;
        size += lst.size;
    }
    int remove(int x)
    {
        cell* temp = first;
        for (int i = 0; i < size; i++)
        {
            if (temp->val == x)
            {
                if (i == 0)
                {
                    first = temp->next;
                    temp->next->prev = nullptr;
                }
                else if (i == size - 1)
                {
                    last = temp->prev;
                    temp->prev->next = nullptr;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                }
                delete temp;
                size--;
                return i;
            }
            temp = temp->next;
        }
        return -1;
    }
    void clean()
    {
        cell* temp = first;
        for (int i = 0; i < size - 1; i++)
        {
            temp = temp->next;
            delete temp->prev;
        }
        delete last;
        first = nullptr;
        last = nullptr;
        size = 0;
    }
    void add(int x, int pos)
    {
        if (pos == 0)
        {
            push_front(x);
            return;
        }
        if (pos == size)
        {
            push_back(x);
            return;
        }
        size++;
        cell* new_cell = new cell;
        new_cell->val = x;
        cell* temp = first->next;
        for (int i = 1; i < size - 1; i++)
        {
            if (i == pos)
            {
                temp->prev->next = new_cell;
                temp->prev = new_cell;
                new_cell->next = temp;
                new_cell->prev = temp->prev;
                return;
            }
            temp = temp->next;
        }
    }
    void dell(int pos)
    {
        if (pos == 0)
        {
            first = first->next;
            delete first->prev;
            first->prev = nullptr;
            size--;
            return;
        }
        if (pos == size - 1)
        {
            last = last->prev;
            delete last->next;
            last->next = nullptr;
            size--;
            return;
        }
        cell* temp = first->next;
        for (int i = 1; i < size - 1; i++)
        {
            if (i == pos)
            {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
                delete temp;
                size--;
                return;
            }
            temp = temp->next;
        }
    }
};

List copy(List orig)
{
    List cop;
    cell* temp = orig.first;
    for (int i = 0; i < orig.size; i++)
    {
        cop.push_back(temp->val);
        temp = temp->next;
    }
    return cop;
}




int main()
{
    List lst, tsl;
    int n;
    cin >> n;
	for (int i = 0; i < n; i++)
	{
		int buf;
		cin >> buf;
        lst.push_back(buf);
	}
    lst.show();
    lst.dell(3);
    lst.show();
	return 0;
}