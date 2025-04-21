# Multimedia Management System

## Description
This application is a comprehensive multimedia management system that allows users to organize and interact with various types of media files including videos, photos, and films. The system implements an object-oriented approach with inheritance hierarchies and provides both a local mode for testing and a server mode for client-server interaction.

## Features
- Create and manage different types of media:
  - Photos with dimensions (width, height)
  - Videos with duration
  - Films with chapters and durations
- Organize media into named collections
- Display detailed information about media and collections
- Play media files using the mpv media player
- Serialize and deserialize data for persistence
- TCP server functionality for remote client access

## Prerequisites
- C++ compiler with C++11 support or later
- mpv media player (required for the playback functionality)

## Installation

### 1. Installing mpv (Required)
The application depends on mpv for media playback. You must install mpv before using this application.

#### For Ubuntu/Debian:
```bash
sudo apt update
sudo apt install mpv
```

#### For Fedora:
```bash
sudo dnf install mpv
```

#### For macOS (using Homebrew):
```bash
brew install mpv
```

#### For Windows:
1. Download the installer from [mpv.io](https://mpv.io/installation/)
2. Install mpv and ensure it's added to your system PATH

### 2. Building the Application

#### Using g++:
```bash
# Compile the server version
g++ -std=c++11 main.cpp MultiMedia.cpp Video.cpp Photo.cpp Film.cpp Collection.cpp MediaManager.cpp tcpserver.cpp -o multimedia_server

# OR compile the local test version (comment the SERVER_v define in main.cpp)
# g++ -std=c++11 main.cpp MultiMedia.cpp Video.cpp Photo.cpp Film.cpp Collection.cpp MediaManager.cpp -o multimedia_local
```

## Usage

### Server Mode
The application by default runs in server mode (with the SERVER_v define active in main.cpp).

1. Start the server:
```bash
./multimedia_server
```

2. The server will start on port 3331 and accept the following commands from clients:
   - `FIND_MEDIA [name]` - Display information about a specific media item
   - `FIND_GROUPE [name]` - Display information about a specific collection
   - `PLAY_MEDIA [name]` - Play a specific media item using mpv
   - `DELETE_MEDIA [name]` - Delete a specific media item
   - `DELETE_COLLECTION [name]` - Delete a specific collection
   - `DISP_ALL` - Display information about all media items and collections

### Local Testing Mode
To use the local testing mode (requires changing the SERVER_v define in main.cpp):

1. Comment out the `#define SERVER_v` line in main.cpp
2. Recompile the application
3. Run the local test version:
```bash
./multimedia_local
```

This mode demonstrates the basic functionality by creating sample media objects, displaying their information, serializing them to a file, deleting them, and then restoring them by deserialization.

## Client Connection
You can connect to the server using telnet or any TCP client:

```bash
telnet localhost 3331
```

Example commands to send:
```
DISP_ALL
FIND_MEDIA video1
PLAY_MEDIA video1
```

## Class Structure

- **MultiMedia**: Abstract base class for all media types
- **Video**: Class for video files with duration
- **Photo**: Class for image files with dimensions
- **Film**: Enhanced video class with chapter information
- **Collection**: Container class that holds multiple media objects
- **MediaManager**: Manages the creation and operations on media objects and collections
- **TCPServer**: Handles client connections and request processing

## Serialization
The application supports saving and loading media objects and collections from files. The serialization format is text-based for easy debugging.

## Example
The server mode initializes with some sample data:
- A video named "video1"
- A photo named "photo1"
- A film named "Film2"
- A collection named "HAPPY" containing the above items
