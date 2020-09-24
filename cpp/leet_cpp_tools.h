#ifndef LEETCPPTOOLS_H
#define LEETCPPTOOLS_H

inline void trimLeftTrailingSpaces(std::string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

inline void trimRightTrailingSpaces(std::string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

inline void trimLeft(std::string &input, const char &trim_ch) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [=](int ch) {
        return ch != trim_ch;
    }));
}

inline void trimRight(std::string &input, const char &trim_ch) {
    input.erase(find_if(input.rbegin(), input.rend(), [=](int ch) {
        return ch != trim_ch;
    }).base(), input.end());
}

template<typename T>
T stoT(const std::string& str);

template<> //int
inline int stoT(const std::string& str) { return std::stoi(str); }

template<> //double
inline double stoT(const std::string& str) { return std::stod(str); }

template<>
inline std::string stoT(const std::string& str) {
    std::string temp = std::string(str);
    trimLeft(temp, '\"'); trimLeft(temp, '\'');
    trimRight(temp, '\"'); trimRight(temp, '\'');
    return std::string(temp);
}

// std::vector<int> stringToIntegerVector(std::string input);

template<typename T>
std::vector<T> stringToVector(std::string input) {
    std::vector<T> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    std::stringstream ss;
    ss.str(input);
    std::string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoT<T>(item));
    }
    return output;
}

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
ListNode* stringToListNode(std::string input);

std::string listNodeToString(ListNode* node);

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

std::string treeNodeToString(TreeNode* root);

TreeNode* stringToTreeNode(std::string input);

void prettyPrintTree(TreeNode* node, std::string prefix /*= ""*/, bool isLeft /*= true*/);

// std::string demangle( const char* symbol )
// {
    // const char* demangled( abi::__cxa_demangle( symbol, 0, 0, 0 ));
	// return demangled ? demangled : symbol;
// }

// std::string demangle( const std::string& symbol )
// {
    // return demangle( symbol.c_str() );
// }

// std::string demangle( const std::type_info& ti )
// {
    // return demangle( ti.name() );
// }

template<class T>
void print_vector(const std::vector<T> &v) {
    std::cout << "[" << std::endl;
    for_each(v.begin(), v.end(), print_vector<typename T::value_type>);
    std::cout << "]" << std::endl;
}

template<>
inline void print_vector<int>(const std::vector<int> &v) {
    std::cout << "[";
    for_each(v.begin(), v.end(), [](const int& n) {std::cout << n << ", ";});
    std::cout << "]" << std::endl;
}

template<>
inline void print_vector<double>(const std::vector<double> &v) {
    std::cout << "[";
    for_each(v.begin(), v.end(), [](const double& n) {std::cout << n << ", ";});
    std::cout << "]" << std::endl;
}

template<>
inline void print_vector<std::string>(const std::vector<std::string> &v) {
    std::cout << "[";
    for_each(v.begin(), v.end(), [](const std::string& n) {std::cout << n << ", ";});
    std::cout << "]" << std::endl;
}

ListNode *listIter(ListNode *p, int n);

ListNode *listEnd(ListNode *p);

#endif //LEETCPPTOOLS_H
