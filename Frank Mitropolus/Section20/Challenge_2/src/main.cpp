// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>

class Song {
 private:
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating;
 public:
  Song() = default;
  Song(std::string name, std::string artist, int rating)
          : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() const {
    return name;
  }
  std::string get_artist() const {
    return artist;
  }
  int get_rating() const {
    return rating;
  }
  
  bool operator<(const Song &rhs) const  {
    return this->name < rhs.name;
  }
  
  bool operator==(const Song &rhs) const  {
    return this->name == rhs.name;
  }
};

std::ostream &operator<<(std::ostream &os, const Song &s) {
  os << std::setw(20) << std::left << s.name
     << std::setw(30) << std::left << s.artist
     << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu() {
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song) {
  std::cout << "\nPlaying:\n"<< song << std::endl;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song) {
  std::cout << std::endl;
  for (auto song : playlist) { std::cout << song << std::endl; }
  std::cout << "Current Song:\n" << current_song << std::endl;
}

int main() {
  std::list<Song> playlist{
    {"God's Plan",        "Drake",                     5},
    {"Never Be The Same", "Camila Cabello",            5},
    {"Pray For Me",       "The Weekend and K. Lamar",  4},
    {"The Middle",        "Zedd, Maren Morris & Grey", 5},
    {"Wait",              "Maroone 5",                 4},
    {"Whatever It Takes", "Imagine Dragons",           3}          
  };
  std::list<Song>::const_iterator currentSong = playlist.cbegin();
  char input;
  display_playlist(playlist, *currentSong);
  do {
    display_menu();
    std::cin.get(input);
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    switch (toupper(input)) {
      case 'Q': { break; }
      case 'F': {
        currentSong = std::cbegin(playlist);
        play_current_song(*currentSong);
        break;
      }
      case 'N': {
        ++currentSong;
        if (currentSong == playlist.cend())
          currentSong = std::cbegin(playlist);
        play_current_song(*currentSong);
        break;
      }
      case 'P': {
        --currentSong;
        if (currentSong == playlist.cend())
          std::advance(currentSong, -1);
        play_current_song(*currentSong);
        break;
      }
      case 'A': {
        std::string name;
        std::string artist;
        int rating;

        std::cout << "Adding and playing new song:\n" << std::left;
        std::cout << std::setw(25) << "Enter song name:";
        std::getline(std::cin, name);
        std::cout << std::setw(25) << "Enter song artist:";
        std::getline(std::cin, artist);
        std::cout << std::setw(25) << "Enter your rating (1-5):" << std::right;
        std::cin >> rating;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        playlist.insert(currentSong, std::move(Song(name, artist, rating)));
        std::advance(currentSong, -1);
        play_current_song(*currentSong);
        break;
      }
      case 'L': {
        display_playlist(playlist, *currentSong);
        break;
      }
    }
  } while (toupper(input) != 'Q');
  
  std::cout << "Thanks for listening!" << std::endl;
  return 0;
}