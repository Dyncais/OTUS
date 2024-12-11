template <typename T>
class SequentialContainer {
private:
    std::vector<T> data;
    
public:
    void push_back(const T& value) {
        data.push_back(value);
    }

    void insert(size_t index, const T& value) {
        if (index > data.size()) {
            throw std::out_of_range("Index out of range in insert");
        }
        data.insert(data.begin() + index, value);
    }

    void erase(size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range in erase");
        }
        data.erase(data.begin() + index);
    }

    size_t size() const {
        return data.size();
    }

    T& operator[](size_t index) {
        if (index >= data.size()) {
            throw std::out_of_range("Index out of range in operator[]");
        }
        return data[index];
    }

    void print() const {
        for (const T& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
};
