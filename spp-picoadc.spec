Name:         spp-picoadc
Version:      1.0
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
