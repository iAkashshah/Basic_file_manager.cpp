#include <iostream>
#include <fstream>
#include <string>
#include <dirent.h> 
#include <unistd.h> 

void listFiles(const std::string& path) {
    DIR* dir;
    struct dirent* entry;
    if ((dir = opendir(path.c_str())) != nullptr) {
        while ((entry = readdir(dir)) != nullptr) {
            std::cout << entry->d_name << std::endl;
        }
        closedir(dir);
    } else {
        std::cerr << "Error opening directory." << std::endl;
    }
}

void createFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        std::cout << "File " << filename << " created successfully." << std::endl;
    } else {
        std::cout << "Error creating file " << filename << "." << std::endl;
    }
}

void deleteFile(const std::string& filename) {
    if (remove(filename.c_str()) == 0) {
        std::cout << "File " << filename << " deleted successfully." << std::endl;
    } else {
        std::cout << "Error deleting file " << filename << "." << std::endl;
    }
}

int main() {
    std::string path = "./"; 
    int choice;
    std::string filename;

    do {
        std::cout << "\n1. List files\n2. Create file\n3. Delete file\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                listFiles(path);
                break;
            case 2:
                std::cout << "Enter filename to create: ";
                std::cin >> filename;
                createFile(filename);
                break;
            case 3:
                std::cout << "Enter filename to delete: ";
                std::cin >> filename;
                deleteFile(filename);
                break;
            case 4:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

