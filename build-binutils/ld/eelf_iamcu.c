/* This file is is generated by a shell script.  DO NOT EDIT! */

/* 32 bit ELF emulation code for elf_iamcu
   Copyright (C) 1991-2024 Free Software Foundation, Inc.
   Written by Steve Chamberlain <sac@cygnus.com>
   ELF support by Ian Lance Taylor <ian@cygnus.com>

   This file is part of the GNU Binutils.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street - Fifth Floor, Boston,
   MA 02110-1301, USA.  */

#define TARGET_IS_elf_iamcu

#include "sysdep.h"
#include "bfd.h"
#include "libiberty.h"
#include "getopt.h"
#include "bfdlink.h"
#include "ctf-api.h"
#include "ld.h"
#include "ldmain.h"
#include "ldmisc.h"
#include "ldexp.h"
#include "ldlang.h"
#include "ldfile.h"
#include "ldemul.h"
#include <ldgram.h>
#include "elf-bfd.h"
#include "ldelf.h"
#include "ldelfgen.h"

/* Declare functions used by various EXTRA_EM_FILEs.  */
static void gldelf_iamcu_before_parse (void);
static void gldelf_iamcu_before_plugin_all_symbols_read
  (void);
static void gldelf_iamcu_after_open (void);
static void gldelf_iamcu_before_allocation (void);
static void gldelf_iamcu_after_allocation (void);


#include "ldlex.h"
#include "elf-linker-x86.h"

static struct elf_linker_x86_params params;

/* This is a convenient point to tell BFD about target specific flags.
   After the output has been created, but before inputs are read.  */

static void
elf_x86_create_output_section_statements (void)
{
  _bfd_elf_linker_x86_set_options (&link_info, &params);
}


static void
elf_x86_before_parse (void)
{
  params.call_nop_byte = 0x67;

  gldelf_iamcu_before_parse ();
}


static void
gldelf_iamcu_before_parse (void)
{
  ldfile_set_output_arch ("iamcu", bfd_arch_iamcu);
  input_flags.dynamic = true;
  config.has_shared = true;
  config.separate_code = false;
  link_info.check_relocs_after_open_input = true;
  link_info.relro = DEFAULT_LD_Z_RELRO;
  link_info.separate_code = DEFAULT_LD_Z_SEPARATE_CODE;
  link_info.warn_execstack = DEFAULT_LD_WARN_EXECSTACK;
  link_info.no_warn_rwx_segments = ! DEFAULT_LD_WARN_RWX_SEGMENTS;
  link_info.default_execstack = DEFAULT_LD_EXECSTACK;
  link_info.error_execstack = DEFAULT_LD_ERROR_EXECSTACK;
  link_info.warn_is_error_for_rwx_segments = DEFAULT_LD_ERROR_RWX_SEGMENTS;
}


/* These variables are used to implement target options */

static char *audit; /* colon (typically) separated list of libs */
static char *depaudit; /* colon (typically) separated list of libs */


/* This is called before calling plugin 'all symbols read' hook.  */

static void
gldelf_iamcu_before_plugin_all_symbols_read (void)
{
  ldelf_before_plugin_all_symbols_read (false, false,
				        false,
					false,
					32, "/home/stroxzu/opt/cross");
}

/* This is called after all the input files have been opened.  */

static void
gldelf_iamcu_after_open (void)
{
  ldelf_after_open (false, false,
		    false, false, 32, "/home/stroxzu/opt/cross");
}


/* This is called after the sections have been attached to output
   sections, but before any sizes or addresses have been set.  */

static void
gldelf_iamcu_before_allocation (void)
{
  ldelf_before_allocation (audit, depaudit, NULL);
}


static void
gldelf_iamcu_after_allocation (void)
{
  int need_layout = bfd_elf_discard_info (link_info.output_bfd, &link_info);

  if (need_layout < 0)
    einfo (_("%X%P: .eh_frame/.stab edit: %E\n"));
  else
    ldelf_map_segments (need_layout);
}

static char *
gldelf_iamcu_get_script (int *isfile)
{
  *isfile = 1;

  if (bfd_link_relocatable (&link_info) && config.build_constructors)
    return "ldscripts/elf_iamcu.xu";
  else if (bfd_link_relocatable (&link_info))
    return "ldscripts/elf_iamcu.xr";
  else if (!config.text_read_only)
    return "ldscripts/elf_iamcu.xbn";
  else if (!config.magic_demand_paged)
    return "ldscripts/elf_iamcu.xn";
  else if (bfd_link_pie (&link_info)
	   && link_info.combreloc
	   && link_info.relro
	   && (link_info.flags & DF_BIND_NOW))
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xdwe";
      else
	return "ldscripts/elf_iamcu.xdw";
    }
  else if (bfd_link_pie (&link_info)
	   && link_info.combreloc)
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xdce";
      else
	return "ldscripts/elf_iamcu.xdc";
    }
  else if (bfd_link_pie (&link_info))
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xde";
      else
	return "ldscripts/elf_iamcu.xd";
    }
  else if (bfd_link_dll (&link_info) && link_info.combreloc
	   && link_info.relro && (link_info.flags & DF_BIND_NOW))
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xswe";
      else
	return "ldscripts/elf_iamcu.xsw";
    }
  else if (bfd_link_dll (&link_info) && link_info.combreloc)
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xsce";
      else
	return "ldscripts/elf_iamcu.xsc";
    }
  else if (bfd_link_dll (&link_info))
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xse";
      else
	return "ldscripts/elf_iamcu.xs";
    }
  else if (link_info.combreloc && link_info.relro
	   && (link_info.flags & DF_BIND_NOW))
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xwe";
      else
	return "ldscripts/elf_iamcu.xw";
    }
  else if (link_info.combreloc)
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xce";
      else
	return "ldscripts/elf_iamcu.xc";
    }
  else
    {
      if (link_info.separate_code)
	return "ldscripts/elf_iamcu.xe";
      else
	return "ldscripts/elf_iamcu.x";
    }
}

 
#define OPTION_LD_GENERATED_UNWIND_INFO	301
#define OPTION_NO_LD_GENERATED_UNWIND_INFO 302


enum elf_options
{
  OPTION_DISABLE_NEW_DTAGS = 400,
  OPTION_ENABLE_NEW_DTAGS,
  OPTION_GROUP,
  OPTION_EH_FRAME_HDR,
  OPTION_NO_EH_FRAME_HDR,
  OPTION_EXCLUDE_LIBS,
  OPTION_HASH_STYLE,
  OPTION_BUILD_ID,
  OPTION_PACKAGE_METADATA,
  OPTION_AUDIT,
  OPTION_COMPRESS_DEBUG
};

static void
gldelf_iamcu_add_options
  (int ns, char **shortopts, int nl, struct option **longopts,
   int nrl ATTRIBUTE_UNUSED, struct option **really_longopts ATTRIBUTE_UNUSED)
{
  static const char xtra_short[] = "z:P:";
  static const struct option xtra_long[] = {
    {"audit", required_argument, NULL, OPTION_AUDIT},
    {"Bgroup", no_argument, NULL, OPTION_GROUP},
    {"build-id", optional_argument, NULL, OPTION_BUILD_ID},
    {"package-metadata", optional_argument, NULL, OPTION_PACKAGE_METADATA},
    {"compress-debug-sections", required_argument, NULL, OPTION_COMPRESS_DEBUG},
    {"depaudit", required_argument, NULL, 'P'},
    {"disable-new-dtags", no_argument, NULL, OPTION_DISABLE_NEW_DTAGS},
    {"enable-new-dtags", no_argument, NULL, OPTION_ENABLE_NEW_DTAGS},
    {"eh-frame-hdr", no_argument, NULL, OPTION_EH_FRAME_HDR},
    {"no-eh-frame-hdr", no_argument, NULL, OPTION_NO_EH_FRAME_HDR},
    {"exclude-libs", required_argument, NULL, OPTION_EXCLUDE_LIBS},
    {"hash-style", required_argument, NULL, OPTION_HASH_STYLE},
    
  {"ld-generated-unwind-info", no_argument, NULL,
   OPTION_LD_GENERATED_UNWIND_INFO},
  {"no-ld-generated-unwind-info", no_argument, NULL,
   OPTION_NO_LD_GENERATED_UNWIND_INFO},

    {NULL, no_argument, NULL, 0}
  };

  *shortopts = (char *) xrealloc (*shortopts, ns + sizeof (xtra_short));
  memcpy (*shortopts + ns, &xtra_short, sizeof (xtra_short));
  *longopts = (struct option *)
    xrealloc (*longopts, nl * sizeof (struct option) + sizeof (xtra_long));
  memcpy (*longopts + nl, &xtra_long, sizeof (xtra_long));
}

#define DEFAULT_BUILD_ID_STYLE	"sha1"

static bool
gldelf_iamcu_handle_option (int optc)
{
  switch (optc)
    {
    default:
      return false;

    case OPTION_BUILD_ID:
      free ((char *) ldelf_emit_note_gnu_build_id);
      ldelf_emit_note_gnu_build_id = NULL;
      if (optarg == NULL)
	optarg = DEFAULT_BUILD_ID_STYLE;
      if (strcmp (optarg, "none"))
	ldelf_emit_note_gnu_build_id = xstrdup (optarg);
      break;

    case OPTION_PACKAGE_METADATA:
      free ((char *) ldelf_emit_note_fdo_package_metadata);
      ldelf_emit_note_fdo_package_metadata = NULL;
      if (optarg != NULL && strlen(optarg) > 0)
	ldelf_emit_note_fdo_package_metadata = xstrdup (optarg);
      break;

    case OPTION_COMPRESS_DEBUG:
      config.compress_debug = bfd_get_compression_algorithm (optarg);
      if (strcasecmp (optarg, "zstd") == 0)
	{
#ifndef HAVE_ZSTD
	  if (config.compress_debug == COMPRESS_DEBUG_ZSTD)
	    einfo (_ ("%F%P: --compress-debug-sections=zstd: ld is not built "
		  "with zstd support\n"));
#endif
	}
      if (config.compress_debug == COMPRESS_UNKNOWN)
	einfo (_("%F%P: invalid --compress-debug-sections option: `%s'\n"),
	       optarg);
      break;
    case OPTION_AUDIT:
	ldelf_append_to_separated_string (&audit, optarg);
	break;

    case 'P':
	ldelf_append_to_separated_string (&depaudit, optarg);
	break;

    case OPTION_DISABLE_NEW_DTAGS:
      link_info.new_dtags = false;
      break;

    case OPTION_ENABLE_NEW_DTAGS:
      link_info.new_dtags = true;
      break;

    case OPTION_EH_FRAME_HDR:
      link_info.eh_frame_hdr_type = DWARF2_EH_HDR;
      break;

    case OPTION_NO_EH_FRAME_HDR:
      link_info.eh_frame_hdr_type = 0;
      break;

    case OPTION_GROUP:
      link_info.flags_1 |= (bfd_vma) DF_1_GROUP;
      /* Groups must be self-contained.  */
      link_info.unresolved_syms_in_objects = RM_DIAGNOSE;
      link_info.unresolved_syms_in_shared_libs = RM_DIAGNOSE;
      break;

    case OPTION_EXCLUDE_LIBS:
      add_excluded_libs (optarg);
      break;

    case OPTION_HASH_STYLE:
      link_info.emit_hash = false;
      link_info.emit_gnu_hash = false;
      if (strcmp (optarg, "sysv") == 0)
	link_info.emit_hash = true;
      else if (strcmp (optarg, "gnu") == 0)
	link_info.emit_gnu_hash = true;
      else if (strcmp (optarg, "both") == 0)
	{
	  link_info.emit_hash = true;
	  link_info.emit_gnu_hash = true;
	}
      else
	einfo (_("%F%P: invalid hash style `%s'\n"), optarg);
      break;

    case 'z':
      if (strcmp (optarg, "defs") == 0)
	link_info.unresolved_syms_in_objects = RM_DIAGNOSE;
      else if (strcmp (optarg, "undefs") == 0)
	link_info.unresolved_syms_in_objects = RM_IGNORE;
      else if (strcmp (optarg, "muldefs") == 0)
	link_info.allow_multiple_definition = true;
      else if (startswith (optarg, "max-page-size="))
	{
	  char *end;

	  link_info.maxpagesize = strtoul (optarg + 14, &end, 0);
	  if (*end
	      || (link_info.maxpagesize & (link_info.maxpagesize - 1)) != 0)
	    einfo (_("%F%P: invalid maximum page size `%s'\n"),
		   optarg + 14);
	  link_info.maxpagesize_is_set = true;
	}
      else if (startswith (optarg, "common-page-size="))
	{
	  char *end;
	  link_info.commonpagesize = strtoul (optarg + 17, &end, 0);
	  if (*end
	      || (link_info.commonpagesize & (link_info.commonpagesize - 1)) != 0)
	    einfo (_("%F%P: invalid common page size `%s'\n"),
		   optarg + 17);
	  link_info.commonpagesize_is_set = true;
	}
      else if (startswith (optarg, "stack-size="))
	{
	  char *end;
	  link_info.stacksize = strtoul (optarg + 11, &end, 0);
	  if (*end || link_info.stacksize < 0)
	    einfo (_("%F%P: invalid stack size `%s'\n"), optarg + 11);
	  if (!link_info.stacksize)
	    /* Use -1 for explicit no-stack, because zero means
	       'default'.   */
	    link_info.stacksize = -1;
	}
      else if (strcmp (optarg, "execstack") == 0)
	{
	  link_info.execstack = true;
	  link_info.noexecstack = false;
	}
      else if (strcmp (optarg, "noexecstack") == 0)
	{
	  link_info.noexecstack = true;
	  link_info.execstack = false;
	}
      else if (strcmp (optarg, "unique-symbol") == 0)
	link_info.unique_symbol = true;
      else if (strcmp (optarg, "nounique-symbol") == 0)
	link_info.unique_symbol = false;
      else if (strcmp (optarg, "globalaudit") == 0)
	{
	  link_info.flags_1 |= DF_1_GLOBAUDIT;
	}
      else if (startswith (optarg, "start-stop-gc"))
	link_info.start_stop_gc = true;
      else if (startswith (optarg, "nostart-stop-gc"))
	link_info.start_stop_gc = false;
      else if (startswith (optarg, "start-stop-visibility="))
	{
	  if (strcmp (optarg, "start-stop-visibility=default") == 0)
	    link_info.start_stop_visibility = STV_DEFAULT;
	  else if (strcmp (optarg, "start-stop-visibility=internal") == 0)
	    link_info.start_stop_visibility = STV_INTERNAL;
	  else if (strcmp (optarg, "start-stop-visibility=hidden") == 0)
	    link_info.start_stop_visibility = STV_HIDDEN;
	  else if (strcmp (optarg, "start-stop-visibility=protected") == 0)
	    link_info.start_stop_visibility = STV_PROTECTED;
	  else
	    einfo (_("%F%P: invalid visibility in `-z %s'; "
		     "must be default, internal, hidden, or protected"),
		   optarg);
	}
      else if (strcmp (optarg, "sectionheader") == 0)
	config.no_section_header = false;
      else if (strcmp (optarg, "nosectionheader") == 0)
	config.no_section_header = true;
      else if (strcmp (optarg, "global") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_GLOBAL;
      else if (strcmp (optarg, "initfirst") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_INITFIRST;
      else if (strcmp (optarg, "interpose") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_INTERPOSE;
      else if (strcmp (optarg, "loadfltr") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_LOADFLTR;
      else if (strcmp (optarg, "nodefaultlib") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_NODEFLIB;
      else if (strcmp (optarg, "nodelete") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_NODELETE;
      else if (strcmp (optarg, "nodlopen") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_NOOPEN;
      else if (strcmp (optarg, "nodump") == 0)
	link_info.flags_1 |= (bfd_vma) DF_1_NODUMP;
      else if (strcmp (optarg, "now") == 0)
	{
	  link_info.flags |= (bfd_vma) DF_BIND_NOW;
	  link_info.flags_1 |= (bfd_vma) DF_1_NOW;
	}
      else if (strcmp (optarg, "lazy") == 0)
	{
	  link_info.flags &= ~(bfd_vma) DF_BIND_NOW;
	  link_info.flags_1 &= ~(bfd_vma) DF_1_NOW;
	}
      else if (strcmp (optarg, "origin") == 0)
	{
	  link_info.flags |= (bfd_vma) DF_ORIGIN;
	  link_info.flags_1 |= (bfd_vma) DF_1_ORIGIN;
	}
      else if (strcmp (optarg, "unique") == 0)
	link_info.gnu_flags_1 |= (bfd_vma) DF_GNU_1_UNIQUE;
      else if (strcmp (optarg, "nounique") == 0)
	link_info.gnu_flags_1 &= ~(bfd_vma) DF_GNU_1_UNIQUE;
      else if (strcmp (optarg, "combreloc") == 0)
	link_info.combreloc = true;
      else if (strcmp (optarg, "nocombreloc") == 0)
	link_info.combreloc = false;
      else if (strcmp (optarg, "nocopyreloc") == 0)
	link_info.nocopyreloc = true;
      else if (strcmp (optarg, "relro") == 0)
	link_info.relro = true;
      else if (strcmp (optarg, "norelro") == 0)
	link_info.relro = false;
      else if (strcmp (optarg, "separate-code") == 0)
	link_info.separate_code = true;
      else if (strcmp (optarg, "noseparate-code") == 0)
	link_info.separate_code = false;
      else if (strcmp (optarg, "common") == 0)
	link_info.elf_stt_common = elf_stt_common;
      else if (strcmp (optarg, "nocommon") == 0)
	link_info.elf_stt_common = no_elf_stt_common;
      else if (strcmp (optarg, "text") == 0)
	link_info.textrel_check = textrel_check_error;
      else if (strcmp (optarg, "notext") == 0)
	link_info.textrel_check = textrel_check_none;
      else if (strcmp (optarg, "textoff") == 0)
	link_info.textrel_check = textrel_check_none;
  
      else if (strcmp (optarg, "noextern-protected-data") == 0)
	link_info.extern_protected_data = false;
      else if (strcmp (optarg, "indirect-extern-access") == 0)
	link_info.indirect_extern_access = 2;
      else if (strcmp (optarg, "noindirect-extern-access") == 0)
	link_info.indirect_extern_access = 0;
 
      else if (strcmp (optarg, "dynamic-undefined-weak") == 0)
	link_info.dynamic_undefined_weak = true;
      else if (strcmp (optarg, "nodynamic-undefined-weak") == 0)
	link_info.dynamic_undefined_weak = false;
 
      else if (strncmp (optarg, "call-nop=", 9) == 0)
	{
	  if (strcmp (optarg + 9, "prefix-addr") == 0)
	    {
	      params.call_nop_as_suffix = false;
	      params.call_nop_byte = 0x67;
	    }
	  else if (strcmp (optarg + 9, "suffix-nop") == 0)
	    {
	      params.call_nop_as_suffix = true;
	      params.call_nop_byte = 0x90;
	    }
	  else if (strncmp (optarg + 9, "prefix-", 7) == 0)
	    {
	      char *end;
	      params.call_nop_byte = strtoul (optarg + 16 , &end, 0);
	      if (*end)
		einfo (_("%F%P: invalid number for -z call-nop=prefix-: %s\n"),
		       optarg + 16);
	      params.call_nop_as_suffix = false;
	    }
	  else if (strncmp (optarg + 9, "suffix-", 7) == 0)
	    {
	      char *end;
	      params.call_nop_byte = strtoul (optarg + 16, &end, 0);
	      if (*end)
		einfo (_("%F%P: invalid number for -z call-nop=suffix-: %s\n"),
		       optarg + 16);
	      params.call_nop_as_suffix = true;
	    }
	  else
	    einfo (_("%F%P: unsupported option: -z %s\n"), optarg);
	}

      else
	einfo (_("%P: warning: -z %s ignored\n"), optarg);
      break;
 
    case OPTION_LD_GENERATED_UNWIND_INFO:
      link_info.no_ld_generated_unwind_info = false;
      break;

    case OPTION_NO_LD_GENERATED_UNWIND_INFO:
      link_info.no_ld_generated_unwind_info = true;
      break;

    }

  return true;
}


static void
gldelf_iamcu_list_options (FILE * file)
{
  
  fprintf (file, _("\
  -z noextern-protected-data  Do not treat protected data symbol as external\n"));
  fprintf (file, _("\
  -z indirect-extern-access   Enable indirect external access\n"));
  fprintf (file, _("\
  -z noindirect-extern-access Disable indirect external access (default)\n"));
 
  fprintf (file, _("\
  -z dynamic-undefined-weak   Make undefined weak symbols dynamic\n\
  -z nodynamic-undefined-weak Do not make undefined weak symbols dynamic\n"));
 
  fprintf (file, _("\
  -z call-nop=PADDING         Use PADDING as 1-byte NOP for branch\n"));

}

struct ld_emulation_xfer_struct ld_elf_iamcu_emulation =
{
  elf_x86_before_parse,
  syslib_default,
  hll_default,
  ldelf_after_parse,
  gldelf_iamcu_before_plugin_all_symbols_read,
  gldelf_iamcu_after_open,
  after_check_relocs_default,
  ldelf_before_place_orphans,
  gldelf_iamcu_after_allocation,
  ldelf_set_output_arch,
  ldemul_default_target,
  gldelf_iamcu_before_allocation,
  gldelf_iamcu_get_script,
  "elf_iamcu",
  "elf32-iamcu",
  finish_default,
  elf_x86_create_output_section_statements,
  ldelf_open_dynamic_archive,
  ldelf_place_orphan,
  NULL,
  NULL,
  gldelf_iamcu_add_options,
  gldelf_iamcu_handle_option,
  NULL,
  gldelf_iamcu_list_options,
  ldelf_load_symbols,
  NULL,
  NULL,
  NULL,
  ldelf_emit_ctf_early,
  ldelf_acquire_strings_for_ctf,
  ldelf_new_dynsym_for_ctf,
  NULL
};
