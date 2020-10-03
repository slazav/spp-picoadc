#ifndef ADC24_H
#define ADC24_H


#include <pico/HRDL.h>
#include <string>
#include <vector>
#include <stdint.h>

// analog channel configuration
struct ChConf_t{
  int16_t en;
  int16_t sngl;
  HRDL_RANGE rng;
  std::vector<int16_t> buf;
  int32_t min, max;
  ChConf_t(): en(false), sngl(false), rng(HRDL_2500_MV),min(-1),max(1) {}
};

class ADC24{

protected:
  std::vector<ChConf_t> chconf; // channel configuration for block mode
  int16_t devh; // device handle
  int16_t devn; // device number (1..20)

public:

  void cmd(const std::vector<std::string> & args);

  bool is_cmd(const std::vector<std::string> & args, const char *name);

  const char * cmd_help() const; // return command help

  /**********************************************************/

  // return list of available devices
  static std::string dev_list();

  // constructor: find and open device with the name
  ADC24(const std::string & name);

  // destructor: close device
  ~ADC24();

  /**********************************************************/

  // General device/program settings

  // Return unit information for a handler (used in list method
  // and constuctor with different handlers).
  static std::string get_unit_info(const int16_t h, const uint16_t info);

  // Get error information and return message
  std::string get_error();

  // Configure the mains noise rejection setting (60 or 50 Hz).
  void set_mains(const bool m60Hz);

  // Get device info.
  std::string get_info();

  // Get available range constants.
  std::string get_ranges();

  // Get available time conversion constants.
  std::string get_tconvs();

  // Measure a single value with full channel setup.
  // (no need for other setup functions)
  // returns overflow flag.
  double get_single(const int ch, const bool single,
      const std::string & rng, const std::string & convt);

  // Block read mode (set channels, set timings, read data block).
  // Using this mode by multiple users (through device server)
  // will require device locking between setting parameters
  // and making the measurement.

  // Set channel parameters.
  void set_channel(int chan, bool enable,
                bool single, const std::string & rng);

  // Disable all channels
  void disable_all();

  // Print channel settings.
  void print_channel(int chan);

  // Set timing parameters.
  void set_timing(int32_t dt, const std::string & convt);

  // Returns the number of channels enabled.
  int chan_get_num();

  // Returns list of enabled channels.
  std::vector<int> chan_get_list();

  // Get block of data.
  std::vector<double> get_block(int32_t nvals);

};

#endif
