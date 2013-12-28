/*
 * Copyright (C) 2011 The Android Open Source Project
 * Copyright (c) 2011-2013, The Linux Foundation. All rights reserved.
 * Not a Contribution.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#ifndef ANDROID_AUDIO_HAL_INTERFACE_H
#define ANDROID_AUDIO_HAL_INTERFACE_H

#include <stdint.h>
#include <strings.h>
#include <sys/cdefs.h>
#include <sys/types.h>

#include <cutils/bitops.h>

#include <hardware/hardware.h>
#include <system/audio.h>
#include <hardware/audio_effect.h>

__BEGIN_DECLS

/**
 * The id of this module
 */
#define AUDIO_HARDWARE_MODULE_ID "audio"

/**
 * Name of the audio devices to open
 */
#define AUDIO_HARDWARE_INTERFACE "audio_hw_if"


/* Use version 0.1 to be compatible with first generation of audio hw module with version_major
 * hardcoded to 1. No audio module API change.
 */
#define AUDIO_MODULE_API_VERSION_0_1 HARDWARE_MODULE_API_VERSION(0, 1)
#define AUDIO_MODULE_API_VERSION_CURRENT AUDIO_MODULE_API_VERSION_0_1

/* First generation of audio devices had version hardcoded to 0. all devices with versions < 1.0
 * will be considered of first generation API.
 */
#define AUDIO_DEVICE_API_VERSION_0_0 HARDWARE_DEVICE_API_VERSION(0, 0)
#define AUDIO_DEVICE_API_VERSION_1_0 HARDWARE_DEVICE_API_VERSION(1, 0)
#define AUDIO_DEVICE_API_VERSION_2_0 HARDWARE_DEVICE_API_VERSION(2, 0)
#define AUDIO_DEVICE_API_VERSION_CURRENT AUDIO_DEVICE_API_VERSION_2_0

/**
 * List of known audio HAL modules. This is the base name of the audio HAL
 * library composed of the "audio." prefix, one of the base names below and
 * a suffix specific to the device.
 * e.g: audio.primary.goldfish.so or audio.a2dp.default.so
 */

#define AUDIO_HARDWARE_MODULE_ID_PRIMARY "primary"
#define AUDIO_HARDWARE_MODULE_ID_A2DP "a2dp"
#define AUDIO_HARDWARE_MODULE_ID_USB "usb"
#define AUDIO_HARDWARE_MODULE_ID_REMOTE_SUBMIX "r_submix"
#define AUDIO_HARDWARE_MODULE_ID_CODEC_OFFLOAD "codec_offload"

/**************************************/

/**
 *  standard audio parameters that the HAL may need to handle
 */

/**
 *  audio device parameters
 */

/* BT SCO Noise Reduction + Echo Cancellation parameters */
#define AUDIO_PARAMETER_KEY_BT_NREC "bt_headset_nrec"
#define AUDIO_PARAMETER_VALUE_ON "on"
#define AUDIO_PARAMETER_VALUE_OFF "off"

/* TTY mode selection */
#define AUDIO_PARAMETER_KEY_TTY_MODE "tty_mode"
#define AUDIO_PARAMETER_VALUE_TTY_OFF "tty_off"
#define AUDIO_PARAMETER_VALUE_TTY_VCO "tty_vco"
#define AUDIO_PARAMETER_VALUE_TTY_HCO "tty_hco"
#define AUDIO_PARAMETER_VALUE_TTY_FULL "tty_full"

/* A2DP sink address set by framework */
#define AUDIO_PARAMETER_A2DP_SINK_ADDRESS "a2dp_sink_address"

/* Screen state */
#define AUDIO_PARAMETER_KEY_SCREEN_STATE "screen_state"

/**
 *  audio stream parameters
 */

#define AUDIO_PARAMETER_STREAM_ROUTING "routing"            // audio_devices_t
#define AUDIO_PARAMETER_STREAM_FORMAT "format"              // audio_format_t
#define AUDIO_PARAMETER_STREAM_CHANNELS "channels"          // audio_channel_mask_t
#define AUDIO_PARAMETER_STREAM_FRAME_COUNT "frame_count"    // size_t
#define AUDIO_PARAMETER_STREAM_INPUT_SOURCE "input_source"  // audio_source_t
#define AUDIO_PARAMETER_STREAM_SAMPLING_RATE "sampling_rate" // uint32_t

/* Query supported formats. The response is a '|' separated list of strings from
 * audio_format_t enum e.g: "sup_formats=AUDIO_FORMAT_PCM_16_BIT" */
#define AUDIO_PARAMETER_STREAM_SUP_FORMATS "sup_formats"
/* Query supported channel masks. The response is a '|' separated list of strings from
 * audio_channel_mask_t enum e.g: "sup_channels=AUDIO_CHANNEL_OUT_STEREO|AUDIO_CHANNEL_OUT_MONO" */
#define AUDIO_PARAMETER_STREAM_SUP_CHANNELS "sup_channels"
/* Query supported sampling rates. The response is a '|' separated list of integer values e.g:
 * "sup_sampling_rates=44100|48000" */
#define AUDIO_PARAMETER_STREAM_SUP_SAMPLING_RATES "sup_sampling_rates"

/**
 * audio codec parameters
 */

#define AUDIO_OFFLOAD_CODEC_PARAMS "music_offload_codec_param"
#define AUDIO_OFFLOAD_CODEC_BIT_PER_SAMPLE "music_offload_bit_per_sample"
#define AUDIO_OFFLOAD_CODEC_BIT_RATE "music_offload_bit_rate"
#define AUDIO_OFFLOAD_CODEC_AVG_BIT_RATE "music_offload_avg_bit_rate"
#define AUDIO_OFFLOAD_CODEC_ID "music_offload_codec_id"
#define AUDIO_OFFLOAD_CODEC_BLOCK_ALIGN "music_offload_block_align"
#define AUDIO_OFFLOAD_CODEC_SAMPLE_RATE "music_offload_sample_rate"
#define AUDIO_OFFLOAD_CODEC_ENCODE_OPTION "music_offload_encode_option"
#define AUDIO_OFFLOAD_CODEC_NUM_CHANNEL  "music_offload_num_channels"
#define AUDIO_OFFLOAD_CODEC_DOWN_SAMPLING  "music_offload_down_sampling"
#define AUDIO_OFFLOAD_CODEC_DELAY_SAMPLES  "delay_samples"
#define AUDIO_OFFLOAD_CODEC_PADDING_SAMPLES  "padding_samples"

#ifdef QCOM_HARDWARE
/* Query handle fm parameter*/
#define AUDIO_PARAMETER_KEY_HANDLE_FM "handle_fm"

/* Query voip flag */
#define AUDIO_PARAMETER_KEY_VOIP_CHECK "voip_flag"

/* Query Fluence type */
#define AUDIO_PARAMETER_KEY_FLUENCE_TYPE "fluence"

/* Query if surround sound recording is supported */
#define AUDIO_PARAMETER_KEY_SSR "ssr"

/* Query if a2dp  is supported */
#define AUDIO_PARAMETER_KEY_HANDLE_A2DP_DEVICE "isA2dpDeviceSupported"

/* Query ADSP Status */
#define AUDIO_PARAMETER_KEY_ADSP_STATUS "ADSP_STATUS"

/* Query if Proxy can be Opend */
#define AUDIO_CAN_OPEN_PROXY "can_open_proxy"

/* Query fm volume */
#define AUDIO_PARAMETER_KEY_FM_VOLUME "fm_volume"
#endif

/**************************************/

/* common audio stream configuration parameters
 * You should memset() the entire structure to zero before use to
 * ensure forward compatibility
 */
struct audio_config {
    uint32_t sample_rate;
    audio_channel_mask_t channel_mask;
    audio_format_t  format;
    audio_offload_info_t offload_info;
};
typedef struct audio_config audio_config_t;

#ifdef QCOM_HARDWARE
/** Structure to save buffer information for applying effects for
 *  LPA buffers */
struct buf_info {
    int bufsize;
    int nBufs;
    int **buffers;
};
#endif

/* common audio stream parameters and operations */
struct audio_stream {

    /**
     * Return the sampling rate in Hz - eg. 44100.
     */
    uint32_t (*get_sample_rate)(const struct audio_stream *stream);

    /* currently unused - use set_parameters with key
     *    AUDIO_PARAMETER_STREAM_SAMPLING_RATE
     */
    int (*set_sample_rate)(struct audio_stream *stream, uint32_t rate);

    /**
     * Return size of input/output buffer in bytes for this stream - eg. 4800.
     * It should be a multiple of the frame size.  See also get_input_buffer_size.
     */
    size_t (*get_buffer_size)(const struct audio_stream *stream);

    /**
     * Return the channel mask -
     *  e.g. AUDIO_CHANNEL_OUT_STEREO or AUDIO_CHANNEL_IN_STEREO
     */
    audio_channel_mask_t (*get_channels)(const struct audio_stream *stream);

    /**
     * Return the audio format - e.g. AUDIO_FORMAT_PCM_16_BIT
     */
    audio_format_t (*get_format)(const struct audio_stream *stream);

    /* currently unused - use set_parameters with key
     *     AUDIO_PARAMETER_STREAM_FORMAT
     */
    int (*set_format)(struct audio_stream *stream, audio_format_t format);

    /**
     * Put the audio hardware input/output into standby mode.
     * Driver should exit from standby mode at the next I/O operation.
     * Returns 0 on success and <0 on failure.
     */
    int (*standby)(struct audio_stream *stream);

    /** dump the state of the audio input/output device */
    int (*dump)(const struct audio_stream *stream, int fd);

    /** Return the set of device(s) which this stream is connected to */
    audio_devices_t (*get_device)(const struct audio_stream *stream);

    /**
     * Currently unused - set_device() corresponds to set_parameters() with key
     * AUDIO_PARAMETER_STREAM_ROUTING for both input and output.
     * AUDIO_PARAMETER_STREAM_INPUT_SOURCE is an additional information used by
     * input streams only.
     */
    int (*set_device)(struct audio_stream *stream, audio_devices_t device);

    /**
     * set/get audio stream parameters. The function accepts a list of
     * parameter key value pairs in the form: key1=value1;key2=value2;...
     *
     * Some keys are reserved for standard parameters (See AudioParameter class)
     *
     * If the implementation does not accept a parameter change while
     * the output is active but the parameter is acceptable otherwise, it must
     * return -ENOSYS.
     *
     * The audio flinger will put the stream in standby and then change the
     * parameter value.
     */
    int (*set_parameters)(struct audio_stream *stream, const char *kv_pairs);

    /*
     * Returns a pointer to a heap allocated string. The caller is responsible
     * for freeing the memory for it using free().
     */
    char * (*get_parameters)(const struct audio_stream *stream,
                             const char *keys);
    int (*add_audio_effect)(const struct audio_stream *stream,
                             effect_handle_t effect);
    int (*remove_audio_effect)(const struct audio_stream *stream,
                             effect_handle_t effect);
};
typedef struct audio_stream audio_stream_t;

/* type of asynchronous write callback events. Mutually exclusive */
typedef enum {
    STREAM_CBK_EVENT_WRITE_READY, /* non blocking write completed */
    STREAM_CBK_EVENT_DRAIN_READY  /* drain completed */
} stream_callback_event_t;

typedef int (*stream_callback_t)(stream_callback_event_t event, void *param, void *cookie);

/* type of drain requested to audio_stream_out->drain(). Mutually exclusive */
typedef enum {
    AUDIO_DRAIN_ALL,            /* drain() returns when all data has been played */
    AUDIO_DRAIN_EARLY_NOTIFY    /* drain() returns a short time before all data
                                   from the current track has been played to
                                   give time for gapless track switch */
} audio_drain_type_t;

/**
 * audio_stream_out is the abstraction interface for the audio output hardware.
 *
 * It provides information about various properties of the audio output
 * hardware driver.
 */

struct audio_stream_out {
    struct audio_stream common;

    /**
     * Return the audio hardware driver estimated latency in milliseconds.
     */
    uint32_t (*get_latency)(const struct audio_stream_out *stream);

    /**
     * Use this method in situations where audio mixing is done in the
     * hardware. This method serves as a direct interface with hardware,
     * allowing you to directly set the volume as apposed to via the framework.
     * This method might produce multiple PCM outputs or hardware accelerated
     * codecs, such as MP3 or AAC.
     */
    int (*set_volume)(struct audio_stream_out *stream, float left, float right);

    /**
     * Write audio buffer to driver. Returns number of bytes written, or a
     * negative status_t. If at least one frame was written successfully prior to the error,
     * it is suggested that the driver return that successful (short) byte count
     * and then return an error in the subsequent call.
     *
     * If set_callback() has previously been called to enable non-blocking mode
     * the write() is not allowed to block. It must write only the number of
     * bytes that currently fit in the driver/hardware buffer and then return
     * this byte count. If this is less than the requested write size the
     * callback function must be called when more space is available in the
     * driver/hardware buffer.
     */
    ssize_t (*write)(struct audio_stream_out *stream, const void* buffer,
                     size_t bytes);

    /* return the number of audio frames written by the audio dsp to DAC since
     * the output has exited standby
     */
    int (*get_render_position)(const struct audio_stream_out *stream,
                               uint32_t *dsp_frames);

    /**
     * get the local time at which the next write to the audio driver will be presented.
     * The units are microseconds, where the epoch is decided by the local audio HAL.
     */
    int (*get_next_write_timestamp)(const struct audio_stream_out *stream,
                                    int64_t *timestamp);

    /**
     * set the callback function for notifying completion of non-blocking
     * write and drain.
     * Calling this function implies that all future write() and drain()
     * must be non-blocking and use the callback to signal completion.
     */
    int (*set_callback)(struct audio_stream_out *stream,
            stream_callback_t callback, void *cookie);

#ifdef QCOM_HARDWARE
    /**
     * start audio data rendering
     */
    int (*start)(struct audio_stream_out *stream);

    /**
     * stop audio data rendering
     */
    int (*stop)(struct audio_stream_out *stream);
#endif

    /**
     * Notifies to the audio driver to stop playback however the queued buffers are
     * retained by the hardware. Useful for implementing pause/resume. Empty implementation
     * if not supported however should be implemented for hardware with non-trivial
     * latency. In the pause state audio hardware could still be using power. User may
     * consider calling suspend after a timeout.
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*pause)(struct audio_stream_out* stream);

    /**
     * Notifies to the audio driver to resume playback following a pause.
     * Returns error if called without matching pause.
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*resume)(struct audio_stream_out* stream);

    /**
     * Requests notification when data buffered by the driver/hardware has
     * been played. If set_callback() has previously been called to enable
     * non-blocking mode, the drain() must not block, instead it should return
     * quickly and completion of the drain is notified through the callback.
     * If set_callback() has not been called, the drain() must block until
     * completion.
     * If type==AUDIO_DRAIN_ALL, the drain completes when all previously written
     * data has been played.
     * If type==AUDIO_DRAIN_EARLY_NOTIFY, the drain completes shortly before all
     * data for the current track has played to allow time for the framework
     * to perform a gapless track switch.
     *
     * Drain must return immediately on stop() and flush() call
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*drain)(struct audio_stream_out* stream, audio_drain_type_t type );

    /**
     * Notifies to the audio driver to flush the queued data. Stream must already
     * be paused before calling flush().
     *
     * Implementation of this function is mandatory for offloaded playback.
     */
    int (*flush)(struct audio_stream_out* stream);

    /**
     * Return a recent count of the number of audio frames presented to an external observer.
     * This excludes frames which have been written but are still in the pipeline.
     * The count is not reset to zero when output enters standby.
     * Also returns the value of CLOCK_MONOTONIC as of this presentation count.
     * The returned count is expected to be 'recent',
     * but does not need to be the most recent possible value.
     * However, the associated time should correspond to whatever count is returned.
     * Example:  assume that N+M frames have been presented, where M is a 'small' number.
     * Then it is permissible to return N instead of N+M,
     * and the timestamp should correspond to N rather than N+M.
     * The terms 'recent' and 'small' are not defined.
     * They reflect the quality of the implementation.
     *
     * 3.0 and higher only.
     */
    int (*get_presentation_position)(const struct audio_stream_out *stream,
                               uint64_t *frames, struct timespec *timestamp);

#ifdef QCOM_HARDWARE
    /**
    * return the current timestamp after quering to the driver
     */
    int (*get_time_stamp)(const struct audio_stream_out *stream,
                               uint64_t *time_stamp);
    /**
    * EOS notification from HAL to Player
     */
    int (*set_observer)(const struct audio_stream_out *stream,
                               void *observer);
    /**
     * Get the physical address of the buffer allocated in the
     * driver
     */
    int (*get_buffer_info) (const struct audio_stream_out *stream,
                                struct buf_info **buf);
    /**
     * Check if next buffer is available. Waits until next buffer is
     * available
     */
    int (*is_buffer_available) (const struct audio_stream_out *stream,
                                     int *isAvail);
#endif

};
typedef struct audio_stream_out audio_stream_out_t;

struct audio_stream_in {
    struct audio_stream common;

    /** set the input gain for the audio driver. This method is for
     *  for future use */
    int (*set_gain)(struct audio_stream_in *stream, float gain);

    /** Read audio buffer in from audio driver. Returns number of bytes read, or a
     *  negative status_t. If at least one frame was read prior to the error,
     *  read should return that byte count and then return an error in the subsequent call.
     */
    ssize_t (*read)(struct audio_stream_in *stream, void* buffer,
                    size_t bytes);

    /**
     * Return the amount of input frames lost in the audio driver since the
     * last call of this function.
     * Audio driver is expected to reset the value to 0 and restart counting
     * upon returning the current value by this function call.
     * Such loss typically occurs when the user space process is blocked
     * longer than the capacity of audio driver buffers.
     *
     * Unit: the number of input audio frames
     */
    uint32_t (*get_input_frames_lost)(struct audio_stream_in *stream);
};
typedef struct audio_stream_in audio_stream_in_t;

/**
 * return the frame size (number of bytes per sample).
 */
static inline size_t audio_stream_frame_size(const struct audio_stream *s)
{
    size_t chan_samp_sz;
#ifdef QCOM_HARDWARE
    uint32_t chan_mask = s->get_channels(s);
    int format = s->get_format(s);
    char *tmpparam;
    int isParamEqual;

    if(!s)
        return 0;
    if (audio_is_input_channel(chan_mask)) {
        chan_mask &= (AUDIO_CHANNEL_IN_STEREO | \
                      AUDIO_CHANNEL_IN_MONO | \
                      AUDIO_CHANNEL_IN_5POINT1);
    }
    tmpparam = s->get_parameters(s, "voip_flag");
    isParamEqual = !strncmp(tmpparam,"voip_flag=1", sizeof("voip_flag=1"));
    free(tmpparam);
    if(isParamEqual) {
        if(format != AUDIO_FORMAT_PCM_8_BIT)
            return popcount(chan_mask) * sizeof(int16_t);
        else
            return popcount(chan_mask) * sizeof(int8_t);
    }

    switch (format) {
    case AUDIO_FORMAT_AMR_NB:
        chan_samp_sz = 32;
        break;
    case AUDIO_FORMAT_EVRC:
        chan_samp_sz = 23;
        break;
    case AUDIO_FORMAT_QCELP:
        chan_samp_sz = 35;
        break;
    case AUDIO_FORMAT_AMR_WB:
        chan_samp_sz = 61;
        break;
    case AUDIO_FORMAT_PCM_16_BIT:
        chan_samp_sz = sizeof(int16_t);
        break;
    case AUDIO_FORMAT_PCM_8_BIT:
    default:
        chan_samp_sz = sizeof(int8_t);
        break;
    }
    return popcount(chan_mask) * chan_samp_sz;
#else
    audio_format_t format = s->get_format(s);

    if (audio_is_linear_pcm(format)) {
        chan_samp_sz = audio_bytes_per_sample(format);
        return popcount(s->get_channels(s)) * chan_samp_sz;
    }

    return sizeof(int8_t);
#endif
}


/**********************************************************************/

/**
 * Every hardware module must have a data structure named HAL_MODULE_INFO_SYM
 * and the fields of this data structure must begin with hw_module_t
 * followed by module specific information.
 */
struct audio_module {
    struct hw_module_t common;
};

struct audio_hw_device {
    struct hw_device_t common;

    /**
     * used by audio flinger to enumerate what devices are supported by
     * each audio_hw_device implementation.
     *
     * Return value is a bitmask of 1 or more values of audio_devices_t
     *
     * NOTE: audio HAL implementations starting with
     * AUDIO_DEVICE_API_VERSION_2_0 do not implement this function.
     * All supported devices should be listed in audio_policy.conf
     * file and the audio policy manager must choose the appropriate
     * audio module based on information in this file.
     */
    uint32_t (*get_supported_devices)(const struct audio_hw_device *dev);

    /**
     * check to see if the audio hardware interface has been initialized.
     * returns 0 on success, -ENODEV on failure.
     */
    int (*init_check)(const struct audio_hw_device *dev);

    /** set the audio volume of a voice call. Range is between 0.0 and 1.0 */
    int (*set_voice_volume)(struct audio_hw_device *dev, float volume);

    /**
     * set the audio volume for all audio activities other than voice call.
     * Range between 0.0 and 1.0. If any value other than 0 is returned,
     * the software mixer will emulate this capability.
     */
    int (*set_master_volume)(struct audio_hw_device *dev, float volume);

    /**
     * Get the current master volume value for the HAL, if the HAL supports
     * master volume control.  AudioFlinger will query this value from the
     * primary audio HAL when the service starts and use the value for setting
     * the initial master volume across all HALs.  HALs which do not support
     * this method may leave it set to NULL.
     */
    int (*get_master_volume)(struct audio_hw_device *dev, float *volume);

#ifdef QCOM_FM_ENABLED
    /** set the fm audio volume. Range is between 0.0 and 1.0 */
    int (*set_fm_volume)(struct audio_hw_device *dev, float volume);
#endif

    /**
     * set_mode is called when the audio mode changes. AUDIO_MODE_NORMAL mode
     * is for standard audio playback, AUDIO_MODE_RINGTONE when a ringtone is
     * playing, and AUDIO_MODE_IN_CALL when a call is in progress.
     */
    int (*set_mode)(struct audio_hw_device *dev, audio_mode_t mode);

    /* mic mute */
    int (*set_mic_mute)(struct audio_hw_device *dev, bool state);
    int (*get_mic_mute)(const struct audio_hw_device *dev, bool *state);

    /* set/get global audio parameters */
    int (*set_parameters)(struct audio_hw_device *dev, const char *kv_pairs);

    /*
     * Returns a pointer to a heap allocated string. The caller is responsible
     * for freeing the memory for it using free().
     */
    char * (*get_parameters)(const struct audio_hw_device *dev,
                             const char *keys);

    /* Returns audio input buffer size according to parameters passed or
     * 0 if one of the parameters is not supported.
     * See also get_buffer_size which is for a particular stream.
     */
    size_t (*get_input_buffer_size)(const struct audio_hw_device *dev,
                                    const struct audio_config *config);

    /** This method creates and opens the audio hardware output stream */
    int (*open_output_stream)(struct audio_hw_device *dev,
                              audio_io_handle_t handle,
                              audio_devices_t devices,
                              audio_output_flags_t flags,
                              struct audio_config *config,
                              struct audio_stream_out **stream_out);

    void (*close_output_stream)(struct audio_hw_device *dev,
                                struct audio_stream_out* stream_out);

    /** This method creates and opens the audio hardware input stream */
    int (*open_input_stream)(struct audio_hw_device *dev,
                             audio_io_handle_t handle,
                             audio_devices_t devices,
                             struct audio_config *config,
                             struct audio_stream_in **stream_in);

    void (*close_input_stream)(struct audio_hw_device *dev,
                               struct audio_stream_in *stream_in);

    /** This method dumps the state of the audio hardware */
    int (*dump)(const struct audio_hw_device *dev, int fd);

    /**
     * set the audio mute status for all audio activities.  If any value other
     * than 0 is returned, the software mixer will emulate this capability.
     */
    int (*set_master_mute)(struct audio_hw_device *dev, bool mute);

    /**
     * Get the current master mute status for the HAL, if the HAL supports
     * master mute control.  AudioFlinger will query this value from the primary
     * audio HAL when the service starts and use the value for setting the
     * initial master mute across all HALs.  HALs which do not support this
     * method may leave it set to NULL.
     */
    int (*get_master_mute)(struct audio_hw_device *dev, bool *mute);
};
typedef struct audio_hw_device audio_hw_device_t;

/** convenience API for opening and closing a supported device */

static inline int audio_hw_device_open(const struct hw_module_t* module,
                                       struct audio_hw_device** device)
{
    return module->methods->open(module, AUDIO_HARDWARE_INTERFACE,
                                 (struct hw_device_t**)device);
}

static inline int audio_hw_device_close(struct audio_hw_device* device)
{
    return device->common.close(&device->common);
}

#ifdef QCOM_HARDWARE
#ifdef __cplusplus
/**
 *Observer class to post the Events from HAL to Flinger
*/
class AudioEventObserver {
public:
    virtual ~AudioEventObserver() {}
    virtual void postEOS(int64_t delayUs) = 0;
};
#endif
#endif
__END_DECLS

#endif  // ANDROID_AUDIO_INTERFACE_H
