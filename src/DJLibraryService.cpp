#include "DJLibraryService.h"
#include "SessionFileParser.h"
#include "MP3Track.h"
#include "WAVTrack.h"
#include <iostream>
#include <memory>
#include <filesystem>


DJLibraryService::DJLibraryService(const Playlist& playlist) 
    : playlist(playlist) {}
/**
 * @brief Load a playlist from track indices referencing the library
 * @param library_tracks Vector of track info from config
 */
void DJLibraryService::buildLibrary(const std::vector<SessionConfig::TrackInfo>& library_tracks) {
    //Todo: Implement buildLibrary method
    std::cout << "TODO: Implement DJLibraryService::buildLibrary method\n"<< library_tracks.size() << " tracks to be loaded into library.\n";
    for (size_t i = 0; i < library_tracks.size(); i++) {
        const SessionConfig::TrackInfo& trackInfo = library_traks[i];
        AudioTrack* track = nullptr;

        if (trackInfo.format == "MP3") {
            track = new MP3Track((trackInfo.title, trackInfo.artists, trackInfo.duration, trackInfo.bpm, trackInfo.extra_param1);
            std::cout << "MP3Track created: " << trackInfo.extra_param1 << std::endl;
        }
        else if (trackInfo.format == "WAV")
            track = new WAVTrack((trackInfo.title, trackInfo.artists, trackInfo.duration, trackInfo.bpm, trackInfo.extra_param1, trackInfo.extra_param2);
            std::cout << "WAVTrack created: " << trackInfo.extra_param1 << trackInfo.extra_param2 << "bit" << std::endl;
        } 
    library_vector.push_back(track);
    }
    std::cout << "[INFO] Track library built: " << library_vector.size() << " tracks loaded" << std::endl;
}

/**
 * @brief Display the current state of the DJ library playlist
 * 
 */
void DJLibraryService::displayLibrary() const {
    std::cout << "=== DJ Library Playlist: " 
              << playlist.get_name() << " ===" << std::endl;

    if (playlist.is_empty()) {
        std::cout << "[INFO] Playlist is empty.\n";
        return;
    }

    // Let Playlist handle printing all track info
    playlist.display();

    std::cout << "Total duration: " << playlist.get_total_duration() << " seconds" << std::endl;
}

/**
 * @brief Get a reference to the current playlist
 * 
 * @return Playlist& 
 */
Playlist& DJLibraryService::getPlaylist() {
    // Your implementation here
    return playlist;
}

/**
 * TODO: Implement findTrack method
 * 
 * HINT: Leverage Playlist's find_track method
 */
AudioTrack* DJLibraryService::findTrack(const std::string& track_title) {
    // Your implementation here
    return nullptr; // Placeholder
}

void DJLibraryService::loadPlaylistFromIndices(const std::string& playlist_name, 
                                               const std::vector<int>& track_indices) {
    // Your implementation here
    std::cout << "[INFO] Loading playlist:" << playlist_name std::endl;
    Playlist currPlaylist(playlist_name);
    size_t tracksAdded = 0;
    for (size_t i = 0; i < track_indices.size(); i++) {
        int trackIndex = track_indices[i];
        size_t index = track_indices[i] - 1;

        if (index >= library_vector.size()) {
            std::cout << "[WARNING] Invalid track index: " << trackIndex << std::endl;
            continue;
        }
        AudioTrack* originalTrack = library_vector[index];
        PointerWrapper<AudioTrack> clonedWrapper = originalTrack->clone();
        AudioTrack* clonedTrack = clonedWrapper.get();

        if (!clonedTrack) {
            std::cout << "[Error] Failed to clone track: " << original->get_title() << std::endl;
            continue;
        }
        clonedTrack->load();
        clonedTrack->analyze_beatgrid();
        currPlaylist.add_track(clonedTrack);
        std::cout << "Added" << clonedTrack->get_title() 
                  << "to playlist" << playlist_name << std::endl;
        tracksAdded++;
    }
    std::cout << "[INFO] Playlist loaded: " << playlist_name 
              << " (" << tracksAdded << " tracks)" << std::endl;
    
    // For now, add a placeholder to fix the linker error
    (void)playlist_name;  // Suppress unused parameter warning
    (void)track_indices;  // Suppress unused parameter warning
}
/**
 * TODO: Implement getTrackTitles method
 * @return Vector of track titles in the playlist
 */
std::vector<std::string> DJLibraryService::getTrackTitles() const {
    // Your implementation here
    return std::vector<std::string>(); // Placeholder
}
