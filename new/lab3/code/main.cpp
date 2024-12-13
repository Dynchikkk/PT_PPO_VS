#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>
#include <queue>
#include "Trimer.h"

namespace fs = std::filesystem;

#define DEFAULT_DIRECTORY "E:/Study/PT_PPO_VS/new/lab1" // Использование прямых слэшей
#define DEFAULT_FILE_EXTENSION ".txt"
#define DEFAULT_THREAD_COUNT 4

std::queue<std::string> fileQueue;
std::mutex queueMutex;
std::mutex printMutex;

void processFile() {
    while (true) {
        std::string filePath;

        {
            std::lock_guard<std::mutex> lock(queueMutex);
            if (fileQueue.empty()) {
                break;
            }
            filePath = fileQueue.front();
            fileQueue.pop();
        }

        try {
            Trimer trimer(filePath);

            std::lock_guard<std::mutex> lock(printMutex);
            std::cout << "\n==File: " << filePath << "==" << std::endl;
            std::cout << "==Headers==" << std::endl;
            for (const auto& header : trimer.Headers) {
                std::cout << header << std::endl;
            }

            std::cout << "==Paragraphs==" << std::endl;
            for (const auto& paragraph : trimer.Paragraphs) {
                std::cout << paragraph << std::endl;
            }

            std::cout << "==Links==" << std::endl;
            for (const auto& link : trimer.Links) {
                std::cout << link << std::endl;
            }
        }
        catch (const std::exception& ex) {
            std::lock_guard<std::mutex> lock(printMutex);
            std::cerr << "Error processing file " << filePath << ": " << ex.what() << std::endl;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string directoryPath;

    if (argc == 2) {
        directoryPath = argv[1];
    }
    else {
        directoryPath = DEFAULT_DIRECTORY;
        std::cout << "No directory argument provided. Using default directory: " << directoryPath << std::endl;
    }

    // Scan the directory for files
    for (const auto& entry : fs::directory_iterator(directoryPath)) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            std::lock_guard<std::mutex> lock(queueMutex);
            fileQueue.push(entry.path().string());
        }
    }

    unsigned int numThreads = std::thread::hardware_concurrency();
    if (numThreads == 0) {
        numThreads = DEFAULT_THREAD_COUNT;
    }

    std::vector<std::thread> threads(numThreads);

    // Create worker threads
    for (unsigned int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(processFile);
    }

    // Wait for all threads to finish
    for (unsigned int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return 0;
}
