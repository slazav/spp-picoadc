Name:         spp-picoadc
Version:      2.4
Release:      alt1

Summary:      SPP interface for Pico ADC devices
Group:        System
URL:          https://github.com/slazav/spp-picoadc
License:      GPL

Packager:     Vladislav Zavjalov <slazav@altlinux.org>

Source:       %name-%version.tar
BuildRequires: gcc-c++

%description
SPP interface for Pico ADC devices

%prep
%setup -q

%build
%make

%install
%makeinstall initdir=%buildroot%_initdir

%files
%_bindir/pico_adc

%changelog
* Thu Jan 25 2024 Vladislav Zavjalov <slazav@altlinux.org> 2.4-alt1
- Move away from pico_rec package to a seperate repo
  https://github.com/slazav/spp-picoadc

* Tue Oct 13 2020 Vladislav Zavjalov <slazav@altlinux.org> 2.3-alt1
This was v.2.3 of pico_osc package
changes in pico_adc:
 - rewrite code keeping old interface
 - modify get_info command: print more information
 - return +/-Inf at overflow
 - allow 1-digit channels in chan_set command
 - check timing configuration in get command
 - new command: set_dig_out, setting digital output
 - new command: disable_all, reset all channel settings
 - new command: get_val, read a single value, no channel setup needed
 - update documentation

* Sat Jul 25 2020 Vladislav Zavjalov <slazav@altlinux.org> 2.2-alt1
This was v.2.2 of pico_osc package
- add pico_adc program (mostly by E.Sergeicheva)
