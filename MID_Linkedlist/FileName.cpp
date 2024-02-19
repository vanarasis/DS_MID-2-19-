#include <iostream>
#include <string>

using namespace std;

// Song class to represent individual songs in the playlist
class Song {
public:
    string title;
    string artist;
    Song* next_song; // Pointer to the next song in the playlist

    // Constructor to initialize the song with title, artist, and next_song pointer
    Song(string _title, string _artist) {
        title = _title;
        artist = _artist;
        next_song = nullptr; // Initialize next_song to nullptr
    }
};

// Playlist class to manage the linked list of songs
class Playlist {
private:
    Song* head; // Pointer to the first song in the playlist
    Song* tail; // Pointer to the last song in the playlist

public:
    // Constructor to initialize an empty playlist
    Playlist() {
        head = nullptr; // Initialize head to nullptr
        tail = nullptr; // Initialize tail to nullptr
    }

    // Method to add a new song to the end of the playlist
    void add_song(string title, string artist) {
        Song* new_song = new Song(title, artist); // Create a new song object
        if (head == nullptr) {
            // If the playlist is empty, set both head and tail to the new song
            head = new_song;
            tail = new_song;
        }
        else {
            // If the playlist is not empty, append the new song to the end and update tail
            tail->next_song = new_song;
            tail = new_song;
        }
    }

    // Method to remove a song from the playlist based on its title
    bool remove_song(string title) {
        Song* current_song = head;
        Song* previous_song = nullptr;
        while (current_song != nullptr) {
            if (current_song->title == title) {
                // If the song with the given title is found
                if (previous_song != nullptr) {
                    // If the song is not the first song in the playlist
                    previous_song->next_song = current_song->next_song;
                    if (current_song == tail) {
                        // If the song is the last song in the playlist, update tail
                        tail = previous_song;
                    }
                }
                else {
                    // If the song is the first song in the playlist, update head
                    head = current_song->next_song;
                    if (head == nullptr) {
                        // If the playlist becomes empty, update tail
                        tail = nullptr;
                    }
                }
                delete current_song; // Delete the removed song from memory
                return true; // Return true to indicate successful removal
            }
            previous_song = current_song;
            current_song = current_song->next_song;
        }
        return false; // Return false if the song with the given title is not found
    }

    // Method to display the songs in the playlist
    void display_playlist() {
        Song* current_song = head;
        if (current_song == nullptr) {
            // If the playlist is empty, print a message
            cout << "Playlist is empty" << endl;
            return;
        }
        cout << "Playlist:" << endl;
        while (current_song != nullptr) {
            // Print the title and artist of each song in the playlist
            cout << current_song->title << " by " << current_song->artist << endl;
            current_song = current_song->next_song; // Move to the next song
        }
    }
};

// Main function to demonstrate the Playlist class
int main() {
    Playlist playlist;

    // Adding songs to the playlist
    playlist.add_song("Song 1", "Artist 1");
    playlist.add_song("Song 2", "Artist 2");
    playlist.add_song("Song 3", "Artist 3");

    // Displaying the playlist
    playlist.display_playlist();

    // Removing a song from the playlist
    playlist.remove_song("Song 2");

    // Displaying the updated playlist
    playlist.display_playlist();

    return 0; // Return 0 to indicate successful program execution
}
