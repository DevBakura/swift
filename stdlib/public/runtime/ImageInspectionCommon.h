//===--- ImageInspectionCommon.h - Image inspection routines -----*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2017 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See https://swift.org/LICENSE.txt for license information
// See https://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//
///
/// \file
///
/// This file unifies common ELF and COFF image inspection routines
///
//===----------------------------------------------------------------------===//

#ifndef SWIFT_RUNTIME_IMAGEINSPECTIONCOMMON_H
#define SWIFT_RUNTIME_IMAGEINSPECTIONCOMMON_H

#if !defined(__MACH__)

#if defined(__ELF__)
#define SWIFT_REFLECTION_METADATA_ELF_NOTE_MAGIC_STRING "swift_reflection_metadata_magic_string"
#endif // defined(__ELF__)

#include "../SwiftShims/Visibility.h"
#include <cstdint>

namespace swift {
struct MetadataSections;
static constexpr const uintptr_t CurrentSectionMetadataVersion = 1;
}

struct SectionInfo {
  uint64_t size;
  const char *data;
};

// Called by injected constructors when a dynamic library is loaded.
SWIFT_RUNTIME_EXPORT
void swift_addNewDSOImage(const void *addr);

#endif // !defined(__MACH__)

#endif // SWIFT_RUNTIME_IMAGEINSPECTIONCOMMON_H