/*
 * Classe que representa a interface do sistema de audio.
 *
 * Autor: Caio Nardelli
 * Data: 18/05/2015
 * Licença: LGPL. Sem copyright.
 */
#ifndef AUDIOMANAGERWRAPPER_H
#define AUDIOMANAGERWRAPPER_H

#include "audiomanager.h"
#include "exception.h"

class AudioManagerWrapper
{
public:
    AudioManagerWrapper();
    ~AudioManagerWrapper();

    void init() throw (Exception);

    AudioManagerSfx * sfx() const;
    AudioManagerMusic * music() const;

private:
    void open_audio();
    void close_audio();

    AudioManagerSfx *sfx_manager;
    AudioManagerMusic *music_manager;
};

#endif
