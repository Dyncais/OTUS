// Шаблонный класс спискового контейнера
template <typename T>
class ListContainer {
private:
    struct Node {
        T value;
        Node* prev;
        Node* next;
        Node(const T& val) : value(val), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    size_t list_size;

public:
    ListContainer() : head(nullptr), tail(nullptr), list_size(0) {}

    ~ListContainer() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        ++list_size;
    }

    void insert(size_t index, const T& value) {
        if (index > list_size) {
            throw std::out_of_range("Index out of range in insert");
        }

        Node* newNode = new Node(value);

        if (index == 0) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
            if (!tail) tail = head;
        } else if (index == list_size) {
            push_back(value);
            return;
        } else {
            Node* current = head;
            for (size_t i = 0; i < index; ++i) {
                current = current->next;
            }
            newNode->next = current;
            newNode->prev = current->prev;
            if (current->prev) current->prev->next = newNode;
            current->prev = newNode;
        }
        ++list_size;
    }

    void erase(size_t index) {
        if (index >= list_size) {
            throw std::out_of_range("Index out of range in erase");
        }

        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }

        if (current->prev) current->prev->next = current->next;
        if (current->next) current->next->prev = current->prev;
        if (current == head) head = current->next;
        if (current == tail) tail = current->prev;

        delete current;
        --list_size;
    }

    size_t size() const {
        return list_size;
    }

    T& operator[](size_t index) {
        Node* current = head;
        for (size_t i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->value;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->value << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};