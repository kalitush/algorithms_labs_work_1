#include <iostream>
using namespace std;

// Узел односвязного списка
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Класс линейного односвязного списка
class LinearList {
private:
    Node* head;
public:
    LinearList() : head(nullptr) {}

    // Добавление элемента в конец списка
    void addElement(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Удаление элемента по значению
    void removeElement(int value) {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Элемент " << value << " удален." << endl;
            return;
        }
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data != value) {
            prev = current;
            current = current->next;
        }
        if (!current) {
            cout << "Элемент " << value << " не найден." << endl;
            return;
        }
        prev->next = current->next;
        delete current;
        cout << "Элемент " << value << " удален." << endl;
    }

    // Вывод списка
    void printList() {
        if (!head) {
            cout << "Список пуст!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Разделение на четные и нечетные элементы
    void splitEvenOdd() {
        LinearList evenList; // Список для четных
        LinearList oddList;  // Список для нечетных

        Node* current = head;
        while (current) {
            if (current->data % 2 == 0) {
                evenList.addElement(current->data);
            } else {
                oddList.addElement(current->data);
            }
            current = current->next;
        }

        cout << "Четные элементы (x1...xk): ";
        evenList.printList();
        cout << "Нечетные элементы (y1...yk): ";
        oddList.printList();
    }

    // Деструктор для освобождения памяти
    ~LinearList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

// Функция для безопасного ввода целого числа
int getIntegerInput() {
    int value;
    while (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ошибка! Введите целое число: ";
    }
    return value;
}

// Функция для вывода меню
void printMenu() {
    cout << "\n=== МЕНЮ ===" << endl;
    cout << "1. Добавить элемент" << endl;
    cout << "2. Удалить элемент" << endl;
    cout << "3. Вывести список" << endl;
    cout << "4. Разделить на четные/нечетные" << endl;
    cout << "5. Выход" << endl;
    cout << "Выберите действие: ";
}

int main() {
    LinearList list;
    int choice, value, n;

    cout << "Введите количество элементов в списке: ";
    n = getIntegerInput();
    cout << "Введите элементы a1, a2, ..., an:" << endl;
    for (int i = 0; i < n; i++) {
        value = getIntegerInput();
        list.addElement(value);
    }

    do {
        printMenu();
        choice = getIntegerInput();
        switch (choice) {
            case 1:
                cout << "Введите значение для добавления: ";
                value = getIntegerInput();
                list.addElement(value);
                break;
            case 2:
                cout << "Введите значение для удаления: ";
                value = getIntegerInput();
                list.removeElement(value);
                break;
            case 3:
                cout << "Текущий список: ";
                list.printList();
                break;
            case 4:
                list.splitEvenOdd();
                break;
            case 5:
                cout << "Выход..." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
        }
    } while (choice != 5);

    return 0;
}