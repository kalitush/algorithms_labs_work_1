#include <iostream>
using namespace std;

// Структура узла линейного односвязного списка
struct Node {
    int data;
    Node* next;
    
    // Конструктор
    Node(int value) : data(value), next(nullptr) {}
};

// Класс для работы с линейным односвязным списком
class LinearList {
private:
    Node* head;

public:
    // Конструктор
    LinearList() : head(nullptr) {}
    
    // Деструктор
    ~LinearList() {
        clear();
    }
    
    // Добавление элемента в конец списка
    void append(int value) {
        Node* newNode = new Node(value);
        
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    // Вывод списка на экран
    void print(const string& message) const {
        cout << message;
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    // Разделение списка на чётные и нечётные элементы
    LinearList separateEvenOdd() {
        LinearList result;
        Node* temp = head;
        
        // Сначала добавляем все чётные элементы
        while (temp) {
            if (temp->data % 2 == 0) {
                result.append(temp->data);
            }
            temp = temp->next;
        }
        
        // Затем добавляем все нечётные элементы
        temp = head;
        while (temp) {
            if (temp->data % 2 != 0) {
                result.append(temp->data);
            }
            temp = temp->next;
        }
        
        return result;
    }
    
    // Очистка списка
    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    // Получение головы списка (для демонстрационных целей)
    Node* getHead() const {
        return head;
    }
};

// Основная программа
int main() {
    LinearList list;
    int n, value;
    
    cout << "ЛАБОРАТОРНАЯ РАБОТА №1" << endl;
    cout << "Вариант 6: Разделение на чётные и нечётные элементы" << endl;
    cout << "=====================================================" << endl;
    
    // Ввод данных
    cout << "Введите количество элементов (n): ";
    cin >> n;
    
    cout << "Введите " << n << " целых чисел:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Элемент " << (i + 1) << ": ";
        cin >> value;
        list.append(value);
    }
    
    // Вывод исходного списка
    list.print("Исходный список: ");
    
    // Разделение на чётные и нечётные
    LinearList result = list.separateEvenOdd();
    
    // Вывод результирующего списка
    result.print("Результирующий список (чётные + нечётные): ");
    
    cout << "=====================================================" << endl;
    cout << "Программа завершена." << endl;
    
    return 0;
}