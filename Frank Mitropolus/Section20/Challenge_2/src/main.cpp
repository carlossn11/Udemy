// Section 20
// Challenge 2
//  Lists

#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <iomanip>
#include <limits>
#include <iterator>

class Song
{
private:
  friend std::ostream &operator<<(std::ostream &os, const Song &s);
  std::string name;
  std::string artist;
  int rating = 0;

public:
  Song() = default;
  Song(std::string name, std::string artist, int rating)
      : name{name}, artist{artist}, rating{rating} {}
  std::string get_name() const
  {
    return name;
  }
  std::string get_artist() const
  {
    return artist;
  }
  int get_rating() const
  {
    return rating;
  }

  bool operator<(const Song &rhs) const
  {
    return this->name < rhs.name;
  }

  bool operator==(const Song &rhs) const
  {
    return this->name == rhs.name;
  }
};

std::ostream &operator<<(std::ostream &os, const Song &s)
{
  os << std::setw(20) << std::left << s.name
     << std::setw(30) << std::left << s.artist
     << std::setw(2) << std::left << s.rating;
  return os;
}

void display_menu()
{
  std::cout << "\nF - Play First Song" << std::endl;
  std::cout << "N - Play Next song" << std::endl;
  std::cout << "P - Play Previous song" << std::endl;
  std::cout << "A - Add and play a new Song at current location" << std::endl;
  std::cout << "L - List the current playlist" << std::endl;
  std::cout << "===============================================" << std::endl;
  std::cout << "Enter a selection (Q to quit): ";
}

void play_current_song(const Song &song)
{
  std::cout << std::left;
  std::cout << "Playing:\n";
  std::cout << std::setw(30) << song.get_name() << std::setw(30) << song.get_artist() << std::setw(30) << song.get_rating() << "\n";
  std::cout << std::right;
}

void display_playlist(const std::list<Song> &playlist, const Song &current_song)
{
  std::cout << std::left;
  for (const auto &song : playlist)
  {
    std::cout << std::setw(30) << song.get_name() << std::setw(30) << song.get_artist() << std::setw(30) << song.get_rating() << "\n";
  }
  std::cout << std::right;

  play_current_song(current_song);
}

void addSong(std::list<Song> &playlist, const std::list<Song>::const_iterator &it)
{
  std::string artist;
  std::string name;
  int rating = 0;

  std::cout << "Artist: ";
  std::getline(std::cin, artist);

  std::cout << "Name: ";
  std::getline(std::cin, name);

  std::cout << "Rating: ";
  std::cin >> rating;
  std::cin.clear();
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  playlist.insert(it, Song(name, artist, rating));
}

void handleAction(const char &input, std::list<Song> &playlist, std::list<Song>::const_iterator &currentSong)
{
  switch (toupper(input))
  {
  case 'F':
  {
    currentSong = playlist.begin();
    play_current_song(*currentSong);
    break;
  }
  case 'N':
  {
    ++currentSong;

    if (currentSong == playlist.end())
    {
      currentSong = playlist.begin();
    }
    break;
  }
  case 'P':
  {
    --currentSong;
    if (currentSong == playlist.end())
    {
      std::advance(currentSong, -1);
    }
    break;
  }
  case 'A':
  {
    addSong(playlist, currentSong);
    break;
  }
  case 'L':
  {
    display_playlist(playlist, *currentSong);
    break;
  }
  default:
  {
    return;
  }
  }
}

int main()
{
  std::list<Song> playlist{
      {"God's Plan", "Drake", 5},
      {"Never Be The Same", "Camila Cabello", 5},
      {"Pray For Me", "The Weekend and K. Lamar", 4},
      {"The Middle", "Zedd, Maren Morris & Grey", 5},
      {"Wait", "Maroone 5", 4},
      {"Whatever It Takes", "Imagine Dragons", 3}};

  std::list<Song>::const_iterator currentSong = playlist.cbegin();

  char input = 'Q';

  do
  {
    display_menu();
    std::cin.get(input);
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    handleAction(input, playlist, currentSong);
  } while (toupper(input) != 'Q');

  std::cout
      << "Thanks for listening!" << std::endl;
  return 0;
}