# 🗺️ Palestinian Cities Pathfinding System

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://github.com/topics/c)
[![Algorithm](https://img.shields.io/badge/Algorithm-Dijkstra%20%26%20BFS-green.svg)](https://github.com/topics/graph-algorithms)
[![Data Structure](https://img.shields.io/badge/Data%20Structure-Graph-orange.svg)](https://github.com/topics/graph)
[![University](https://img.shields.io/badge/University-Birzeit-red.svg)](https://www.birzeit.edu)

> **A comprehensive pathfinding system that finds the shortest routes between Palestinian cities using graph algorithms**

## 🌟 Overview

This project implements two fundamental graph traversal algorithms - **Dijkstra's Algorithm** and **Breadth-First Search (BFS)** - to find the shortest path between 15 Palestinian cities. The system provides an interactive command-line interface that allows users to select source and destination cities and compare the efficiency of both algorithms.

## 🏛️ Academic Information

- **Course**: COMP2421 - Data Structures (Spring 2023)
- **University**: Birzeit University
- **Department**: Computer Science
- **Student**: Al_Hasan Khaled Qarmash (ID: 1210611)
- **Project**: #4 - Graph Algorithms Implementation

## 🎯 Features

### 🔥 Core Functionality
- **🚀 Dual Algorithm Implementation**: Compare Dijkstra's and BFS algorithms side-by-side
- **🏙️ 15 Palestinian Cities**: Navigate through major Palestinian cities including Jerusalem, Ramallah, Gaza, Hebron, and more
- **📊 Distance Calculation**: Real-world distances between cities for accurate pathfinding
- **💾 File I/O Operations**: Load city data from external files and save results
- **🎨 Interactive CLI**: User-friendly command-line interface with clear navigation

### 🛠️ Technical Features
- **Graph Representation**: Adjacency matrix implementation for efficient city connections
- **Memory Optimization**: Efficient data structures for handling city networks
- **Path Reconstruction**: Complete path visualization from source to destination
- **Cost Analysis**: Total distance calculation for route planning

## 🗺️ Supported Cities

| Region | Cities |
|--------|--------|
| **North** | Akka, Haifa, Nazareth, Jenin |
| **Center** | Jaffa, Tulkarem, Qalqilya, Ramallah, Nablus, Tubas, Salfit |
| **South** | Bethlehem, Hebron, Jerusalem, Jericho |

## 🚀 Getting Started

### Prerequisites
- **C Compiler** (GCC recommended)
- **Windows/Linux/macOS** environment
- **Cities.txt** file with city distance data

### 📥 Installation

1. **Clone the repository**
   ```bash
   git clone[ https://github.com/yourusername/palestinian-cities-pathfinding.git](https://github.com/HasanQarmash/dijkstra-bfs-palestine-navigator.git)
   cd dijkstra-bfs-palestine-navigator
   ```

2. **Compile the program**
   ```bash
   gcc -o pathfinder P4.1210611.HasanQarmash.2.c
   ```

3. **Run the application**
   ```bash
   ./pathfinder
   ```

## 📖 Usage Guide

### 🎮 Menu Options

1. **Load Cities Data** 📁
   - Reads city connections and distances from `Cities.txt`
   - Initializes the graph structure

2. **Select Source City** 🏁
   - Choose your starting point from 15 available cities
   - Input validation ensures correct city selection

3. **Select Destination City** 🎯
   - Pick your destination from the city list
   - System displays available cities for easy selection

4. **Calculate & Export Results** 📊
   - Runs both Dijkstra's and BFS algorithms
   - Displays paths and distances in console
   - Exports results to `shortest_distance.txt`

### 💡 Example Usage

```
////////////////////////  { WELCOME BACK IN Google Maps }  //////////////////////////////

Enter your choice:

1. Read From File
2. Enter source
3. Enter destination  
4. Exit and print shortest path

> 1
Cities loaded from file.

> 2
Enter the source city: Ramallah

> 3
Enter the destination city: Jerusalem

Shortest path (Dijkstra): ->Ramallah ->Jerusalem
Total shortest cost by (Dijkstra) method: 15 km

Shortest path by (BFS) method: ->Ramallah ->Jerusalem  
Total distance: 15 km
```

## 🧮 Algorithm Analysis

### 🎯 Dijkstra's Algorithm
- **Time Complexity**: O(V²)
- **Space Complexity**: O(V)
- **Best For**: Weighted graphs with positive weights
- **Guarantees**: Optimal shortest path

### 🔍 Breadth-First Search (BFS)
- **Time Complexity**: O(V + E)
- **Space Complexity**: O(V)
- **Best For**: Unweighted graphs or finding shortest hop count
- **Guarantees**: Shortest path in terms of number of edges

## 📁 Project Structure

```
palestinian-cities-pathfinding/
├── 📄 P4.1210611.HasanQarmash.2.c    # Main source code
├── 📄 README.md                      # Project documentation
├── 📄 shortest_distance.txt          # Output results file
├── 📄 Cities.txt                     # Input city data
├── 📄 Project 4 Spring 2023.pdf      # Project requirements
├── 🗂️ bin/Debug/                     # Compiled executables
└── 🗂️ obj/Debug/                     # Object files
```

## 📊 Sample Output

The program generates detailed output showing both algorithm results:

```
---------------------------------
shortest path by BFS method
-> Qalqilya-> Jaffa-> Ramallah
---------------------------------

---------------------------------
shortest path by Dijkstra method
-> Qalqilya-> Salfit-> Ramallah
---------------------------------
```


## 📜 License

This project is created for academic purposes as part of the Data Structures course at Birzeit University.

## 👨‍💻 Author

**Al_Hasan Khaled Qarmash**
- 🎓 Student ID: 1210611
- 🏛️ Birzeit University - Computer Science Department
- 📧 Contact: [Your Email]
- 💼 LinkedIn: [Your LinkedIn Profile]

---

<div align="center">

### 🌟 If you found this project helpful, please give it a star! ⭐

**Made with ❤️ for Palestine 🇵🇸**

*Connecting Palestinian cities through code and algorithms*

</div>
