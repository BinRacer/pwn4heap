## Notice

```C
#define _IO_str_jumps                    (__io_vtables[IO_STR_JUMPS])
#define _IO_wstr_jumps                   (__io_vtables[IO_WSTR_JUMPS])
#define _IO_file_jumps                   (__io_vtables[IO_FILE_JUMPS])
#define _IO_file_jumps_mmap              (__io_vtables[IO_FILE_JUMPS_MMAP])
#define _IO_file_jumps_maybe_mmap        (__io_vtables[IO_FILE_JUMPS_MAYBE_MMAP])
#define _IO_wfile_jumps                  (__io_vtables[IO_WFILE_JUMPS])
#define _IO_wfile_jumps_mmap             (__io_vtables[IO_WFILE_JUMPS_MMAP])
#define _IO_wfile_jumps_maybe_mmap       (__io_vtables[IO_WFILE_JUMPS_MAYBE_MMAP])
#define _IO_cookie_jumps                 (__io_vtables[IO_COOKIE_JUMPS])
#define _IO_proc_jumps                   (__io_vtables[IO_PROC_JUMPS])
#define _IO_mem_jumps                    (__io_vtables[IO_MEM_JUMPS])
#define _IO_wmem_jumps                   (__io_vtables[IO_WMEM_JUMPS])
#define _IO_printf_buffer_as_file_jumps  (__io_vtables[IO_PRINTF_BUFFER_AS_FILE_JUMPS])
#define _IO_wprintf_buffer_as_file_jumps (__io_vtables[IO_WPRINTF_BUFFER_AS_FILE_JUMPS])
#define _IO_old_file_jumps               (__io_vtables[IO_OLD_FILE_JUMPS])
#define _IO_old_proc_jumps               (__io_vtables[IO_OLD_PROC_JUMPS])
#define _IO_old_cookie_jumps             (__io_vtables[IO_OLD_COOKIED_JUMPS])

const struct _IO_jump_t __io_vtables[] attribute_relro =
{
  /* _IO_str_jumps  */
  [IO_STR_JUMPS] =
  {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_str_finish),
    JUMP_INIT (overflow, _IO_str_overflow),
    JUMP_INIT (underflow, _IO_str_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_str_pbackfail),
    JUMP_INIT (xsputn, _IO_default_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_str_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_default_setbuf),
    JUMP_INIT (sync, _IO_default_sync),
    JUMP_INIT (doallocate, _IO_default_doallocate),
    JUMP_INIT (read, _IO_default_read),
    JUMP_INIT (write, _IO_default_write),
    JUMP_INIT (seek, _IO_default_seek),
    JUMP_INIT (close, _IO_default_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_wstr_jumps  */
  [IO_WSTR_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_wstr_finish),
    JUMP_INIT (overflow, (_IO_overflow_t) _IO_wstr_overflow),
    JUMP_INIT (underflow, (_IO_underflow_t) _IO_wstr_underflow),
    JUMP_INIT (uflow, (_IO_underflow_t) _IO_wdefault_uflow),
    JUMP_INIT (pbackfail, (_IO_pbackfail_t) _IO_wstr_pbackfail),
    JUMP_INIT (xsputn, _IO_wdefault_xsputn),
    JUMP_INIT (xsgetn, _IO_wdefault_xsgetn),
    JUMP_INIT (seekoff, _IO_wstr_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_default_setbuf),
    JUMP_INIT (sync, _IO_default_sync),
    JUMP_INIT (doallocate, _IO_wdefault_doallocate),
    JUMP_INIT (read, _IO_default_read),
    JUMP_INIT (write, _IO_default_write),
    JUMP_INIT (seek, _IO_default_seek),
    JUMP_INIT (close, _IO_default_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_file_jumps  */
  [IO_FILE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_file_finish),
    JUMP_INIT (overflow, _IO_file_overflow),
    JUMP_INIT (underflow, _IO_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_file_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn),
    JUMP_INIT (seekoff, _IO_new_file_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_new_file_setbuf),
    JUMP_INIT (sync, _IO_new_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_file_jumps_mmap  */
  [IO_FILE_JUMPS_MMAP] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_file_finish),
    JUMP_INIT (overflow, _IO_file_overflow),
    JUMP_INIT (underflow, _IO_file_underflow_mmap),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_new_file_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn_mmap),
    JUMP_INIT (seekoff, _IO_file_seekoff_mmap),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, (_IO_setbuf_t) _IO_file_setbuf_mmap),
    JUMP_INIT (sync, _IO_file_sync_mmap),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close_mmap),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_file_jumps_maybe_mmap  */
  [IO_FILE_JUMPS_MAYBE_MMAP] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_file_finish),
    JUMP_INIT (overflow, _IO_file_overflow),
    JUMP_INIT (underflow, _IO_file_underflow_maybe_mmap),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_new_file_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn_maybe_mmap),
    JUMP_INIT (seekoff, _IO_file_seekoff_maybe_mmap),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, (_IO_setbuf_t) _IO_file_setbuf_mmap),
    JUMP_INIT (sync, _IO_new_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_wfile_jumps  */
  [IO_WFILE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_new_file_finish),
    JUMP_INIT (overflow, (_IO_overflow_t) _IO_wfile_overflow),
    JUMP_INIT (underflow, (_IO_underflow_t) _IO_wfile_underflow),
    JUMP_INIT (uflow, (_IO_underflow_t) _IO_wdefault_uflow),
    JUMP_INIT (pbackfail, (_IO_pbackfail_t) _IO_wdefault_pbackfail),
    JUMP_INIT (xsputn, _IO_wfile_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn),
    JUMP_INIT (seekoff, _IO_wfile_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_new_file_setbuf),
    JUMP_INIT (sync, (_IO_sync_t) _IO_wfile_sync),
    JUMP_INIT (doallocate, _IO_wfile_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_wfile_jumps_mmap  */
  [IO_WFILE_JUMPS_MMAP] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_new_file_finish),
    JUMP_INIT (overflow, (_IO_overflow_t) _IO_wfile_overflow),
    JUMP_INIT (underflow, (_IO_underflow_t) _IO_wfile_underflow_mmap),
    JUMP_INIT (uflow, (_IO_underflow_t) _IO_wdefault_uflow),
    JUMP_INIT (pbackfail, (_IO_pbackfail_t) _IO_wdefault_pbackfail),
    JUMP_INIT (xsputn, _IO_wfile_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn),
    JUMP_INIT (seekoff, _IO_wfile_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_file_setbuf_mmap),
    JUMP_INIT (sync, (_IO_sync_t) _IO_wfile_sync),
    JUMP_INIT (doallocate, _IO_wfile_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close_mmap),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_wfile_jumps_maybe_mmap  */
  [IO_WFILE_JUMPS_MAYBE_MMAP] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_new_file_finish),
    JUMP_INIT (overflow, (_IO_overflow_t) _IO_wfile_overflow),
    JUMP_INIT (underflow, (_IO_underflow_t) _IO_wfile_underflow_maybe_mmap),
    JUMP_INIT (uflow, (_IO_underflow_t) _IO_wdefault_uflow),
    JUMP_INIT (pbackfail, (_IO_pbackfail_t) _IO_wdefault_pbackfail),
    JUMP_INIT (xsputn, _IO_wfile_xsputn),
    JUMP_INIT (xsgetn, _IO_file_xsgetn),
    JUMP_INIT (seekoff, _IO_wfile_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_file_setbuf_mmap),
    JUMP_INIT (sync, (_IO_sync_t) _IO_wfile_sync),
    JUMP_INIT (doallocate, _IO_wfile_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_cookie_jumps  */
  [IO_COOKIE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_file_finish),
    JUMP_INIT (overflow, _IO_file_overflow),
    JUMP_INIT (underflow, _IO_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_file_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_cookie_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_file_setbuf),
    JUMP_INIT (sync, _IO_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_cookie_read),
    JUMP_INIT (write, _IO_cookie_write),
    JUMP_INIT (seek, _IO_cookie_seek),
    JUMP_INIT (close, _IO_cookie_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue),
  },
  /* _IO_proc_jumps  */
  [IO_PROC_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_new_file_finish),
    JUMP_INIT (overflow, _IO_new_file_overflow),
    JUMP_INIT (underflow, _IO_new_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_new_file_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_new_file_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_new_file_setbuf),
    JUMP_INIT (sync, _IO_new_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_new_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_new_proc_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_mem_jumps  */
  [IO_MEM_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_mem_finish),
    JUMP_INIT (overflow, _IO_str_overflow),
    JUMP_INIT (underflow, _IO_str_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_str_pbackfail),
    JUMP_INIT (xsputn, _IO_default_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_str_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_default_setbuf),
    JUMP_INIT (sync, _IO_mem_sync),
    JUMP_INIT (doallocate, _IO_default_doallocate),
    JUMP_INIT (read, _IO_default_read),
    JUMP_INIT (write, _IO_default_write),
    JUMP_INIT (seek, _IO_default_seek),
    JUMP_INIT (close, _IO_default_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  /* _IO_wmem_jumps  */
  [IO_WMEM_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_wmem_finish),
    JUMP_INIT (overflow, (_IO_overflow_t) _IO_wstr_overflow),
    JUMP_INIT (underflow, (_IO_underflow_t) _IO_wstr_underflow),
    JUMP_INIT (uflow, (_IO_underflow_t) _IO_wdefault_uflow),
    JUMP_INIT (pbackfail, (_IO_pbackfail_t) _IO_wstr_pbackfail),
    JUMP_INIT (xsputn, _IO_wdefault_xsputn),
    JUMP_INIT (xsgetn, _IO_wdefault_xsgetn),
    JUMP_INIT (seekoff, _IO_wstr_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_default_setbuf),
    JUMP_INIT (sync, _IO_wmem_sync),
    JUMP_INIT (doallocate, _IO_wdefault_doallocate),
    JUMP_INIT (read, _IO_default_read),
    JUMP_INIT (write, _IO_default_write),
    JUMP_INIT (seek, _IO_default_seek),
    JUMP_INIT (close, _IO_default_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
  [IO_PRINTF_BUFFER_AS_FILE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, NULL),
    JUMP_INIT (overflow, __printf_buffer_as_file_overflow),
    JUMP_INIT (underflow, NULL),
    JUMP_INIT (uflow, NULL),
    JUMP_INIT (pbackfail, NULL),
    JUMP_INIT (xsputn, __printf_buffer_as_file_xsputn),
    JUMP_INIT (xsgetn, NULL),
    JUMP_INIT (seekoff, NULL),
    JUMP_INIT (seekpos, NULL),
    JUMP_INIT (setbuf, NULL),
    JUMP_INIT (sync, NULL),
    JUMP_INIT (doallocate, NULL),
    JUMP_INIT (read, NULL),
    JUMP_INIT (write, NULL),
    JUMP_INIT (seek, NULL),
    JUMP_INIT (close, NULL),
    JUMP_INIT (stat, NULL),
    JUMP_INIT (showmanyc, NULL),
    JUMP_INIT (imbue, NULL)
  },
  [IO_WPRINTF_BUFFER_AS_FILE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, NULL),
    JUMP_INIT (overflow, (_IO_overflow_t) __wprintf_buffer_as_file_overflow),
    JUMP_INIT (underflow, NULL),
    JUMP_INIT (uflow, NULL),
    JUMP_INIT (pbackfail, NULL),
    JUMP_INIT (xsputn, __wprintf_buffer_as_file_xsputn),
    JUMP_INIT (xsgetn, NULL),
    JUMP_INIT (seekoff, NULL),
    JUMP_INIT (seekpos, NULL),
    JUMP_INIT (setbuf, NULL),
    JUMP_INIT (sync, NULL),
    JUMP_INIT (doallocate, NULL),
    JUMP_INIT (read, NULL),
    JUMP_INIT (write, NULL),
    JUMP_INIT (seek, NULL),
    JUMP_INIT (close, NULL),
    JUMP_INIT (stat, NULL),
    JUMP_INIT (showmanyc, NULL),
    JUMP_INIT (imbue, NULL)
  },

#if SHLIB_COMPAT (libc, GLIBC_2_0, GLIBC_2_1)
  /* _IO_old_file_jumps  */
  [IO_OLD_FILE_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_old_file_finish),
    JUMP_INIT (overflow, _IO_old_file_overflow),
    JUMP_INIT (underflow, _IO_old_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_old_file_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_old_file_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_old_file_setbuf),
    JUMP_INIT (sync, _IO_old_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_old_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_file_close),
    JUMP_INIT (stat, _IO_file_stat)
  },
  /*  _IO_old_proc_jumps  */
  [IO_OLD_PROC_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_old_file_finish),
    JUMP_INIT (overflow, _IO_old_file_overflow),
    JUMP_INIT (underflow, _IO_old_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_old_file_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_old_file_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_old_file_setbuf),
    JUMP_INIT (sync, _IO_old_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_file_read),
    JUMP_INIT (write, _IO_old_file_write),
    JUMP_INIT (seek, _IO_file_seek),
    JUMP_INIT (close, _IO_old_proc_close),
    JUMP_INIT (stat, _IO_file_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue)
  },
#endif

#if SHLIB_COMPAT (libc, GLIBC_2_0, GLIBC_2_2)
  /* _IO_old_cookie_jumps  */
  [IO_OLD_COOKIED_JUMPS] = {
    JUMP_INIT_DUMMY,
    JUMP_INIT (finish, _IO_file_finish),
    JUMP_INIT (overflow, _IO_file_overflow),
    JUMP_INIT (underflow, _IO_file_underflow),
    JUMP_INIT (uflow, _IO_default_uflow),
    JUMP_INIT (pbackfail, _IO_default_pbackfail),
    JUMP_INIT (xsputn, _IO_file_xsputn),
    JUMP_INIT (xsgetn, _IO_default_xsgetn),
    JUMP_INIT (seekoff, _IO_cookie_seekoff),
    JUMP_INIT (seekpos, _IO_default_seekpos),
    JUMP_INIT (setbuf, _IO_file_setbuf),
    JUMP_INIT (sync, _IO_file_sync),
    JUMP_INIT (doallocate, _IO_file_doallocate),
    JUMP_INIT (read, _IO_cookie_read),
    JUMP_INIT (write, _IO_cookie_write),
    JUMP_INIT (seek, _IO_old_cookie_seek),
    JUMP_INIT (close, _IO_cookie_close),
    JUMP_INIT (stat, _IO_default_stat),
    JUMP_INIT (showmanyc, _IO_default_showmanyc),
    JUMP_INIT (imbue, _IO_default_imbue),
  },
#endif
};
_Static_assert (array_length (__io_vtables) == IO_VTABLES_NUM,

struct _IO_codecvt
{
  _IO_iconv_t __cd_in;
  _IO_iconv_t __cd_out;
};

typedef struct
{
  struct __gconv_step *step;
  struct __gconv_step_data step_data;
} _IO_iconv_t;

struct __gconv_step
{
  struct __gconv_loaded_object *__shlib_handle;
  const char *__modname;

  /* For internal use by glibc.  (Accesses to this member must occur
     when the internal __gconv_lock mutex is acquired).  */
  int __counter;

  char *__from_name;
  char *__to_name;

  __gconv_fct __fct;
  __gconv_btowc_fct __btowc_fct;
  __gconv_init_fct __init_fct;
  __gconv_end_fct __end_fct;

  /* Information about the number of bytes needed or produced in this
     step.  This helps optimizing the buffer sizes.  */
  int __min_needed_from;
  int __max_needed_from;
  int __min_needed_to;
  int __max_needed_to;

  /* Flag whether this is a stateful encoding or not.  */
  int __stateful;

  void *__data;		/* Pointer to step-local data.  */
};

struct _IO_wide_data
{
  wchar_t *_IO_read_ptr;	/* Current read pointer */
  wchar_t *_IO_read_end;	/* End of get area. */
  wchar_t *_IO_read_base;	/* Start of putback+get area. */
  wchar_t *_IO_write_base;	/* Start of put area. */
  wchar_t *_IO_write_ptr;	/* Current put pointer. */
  wchar_t *_IO_write_end;	/* End of put area. */
  wchar_t *_IO_buf_base;	/* Start of reserve area. */
  wchar_t *_IO_buf_end;		/* End of reserve area. */
  /* The following fields are used to support backing up and undo. */
  wchar_t *_IO_save_base;	/* Pointer to start of non-current get area. */
  wchar_t *_IO_backup_base;	/* Pointer to first valid character of
				   backup area */
  wchar_t *_IO_save_end;	/* Pointer to end of non-current get area. */

  __mbstate_t _IO_state;
  __mbstate_t _IO_last_state;
  struct _IO_codecvt _codecvt;

  wchar_t _shortbuf[1];

  const struct _IO_jump_t *_wide_vtable;
};
```

```C
wint_t
_IO_wfile_underflow (FILE *fp)
{
  struct _IO_codecvt *cd;
  enum __codecvt_result status;
  ssize_t count;

  /* C99 requires EOF to be "sticky".  */
  if (fp->_flags & _IO_EOF_SEEN)
    return WEOF;

  if (__glibc_unlikely (fp->_flags & _IO_NO_READS))
    {
      fp->_flags |= _IO_ERR_SEEN;
      __set_errno (EBADF);
      return WEOF;
    }
  if (fp->_wide_data->_IO_read_ptr < fp->_wide_data->_IO_read_end)
    return *fp->_wide_data->_IO_read_ptr;

  cd = fp->_codecvt;

  /* Maybe there is something left in the external buffer.  */
  if (fp->_IO_read_ptr < fp->_IO_read_end)
    {
      /* There is more in the external.  Convert it.  */
      const char *read_stop = (const char *) fp->_IO_read_ptr;

      fp->_wide_data->_IO_last_state = fp->_wide_data->_IO_state;
      fp->_wide_data->_IO_read_base = fp->_wide_data->_IO_read_ptr =
	fp->_wide_data->_IO_buf_base;
      status = __libio_codecvt_in (cd, &fp->_wide_data->_IO_state,
				   fp->_IO_read_ptr, fp->_IO_read_end,
				   &read_stop,
				   fp->_wide_data->_IO_read_ptr,
				   fp->_wide_data->_IO_buf_end,
				   &fp->_wide_data->_IO_read_end);

      fp->_IO_read_base = fp->_IO_read_ptr;
      fp->_IO_read_ptr = (char *) read_stop;

      /* If we managed to generate some text return the next character.  */
      if (fp->_wide_data->_IO_read_ptr < fp->_wide_data->_IO_read_end)
	return *fp->_wide_data->_IO_read_ptr;

      if (status == __codecvt_error)
	{
	  __set_errno (EILSEQ);
	  fp->_flags |= _IO_ERR_SEEN;
	  return WEOF;
	}

      /* Move the remaining content of the read buffer to the beginning.  */
      memmove (fp->_IO_buf_base, fp->_IO_read_ptr,
	       fp->_IO_read_end - fp->_IO_read_ptr);
      fp->_IO_read_end = (fp->_IO_buf_base
			  + (fp->_IO_read_end - fp->_IO_read_ptr));
      fp->_IO_read_base = fp->_IO_read_ptr = fp->_IO_buf_base;
    }
  else
    fp->_IO_read_base = fp->_IO_read_ptr = fp->_IO_read_end =
      fp->_IO_buf_base;

  if (fp->_IO_buf_base == NULL)
    {
      /* Maybe we already have a push back pointer.  */
      if (fp->_IO_save_base != NULL)
	{
	  free (fp->_IO_save_base);
	  fp->_flags &= ~_IO_IN_BACKUP;
	}
      _IO_doallocbuf (fp);

      fp->_IO_read_base = fp->_IO_read_ptr = fp->_IO_read_end =
	fp->_IO_buf_base;
    }

  fp->_IO_write_base = fp->_IO_write_ptr = fp->_IO_write_end =
    fp->_IO_buf_base;

  if (fp->_wide_data->_IO_buf_base == NULL)
    {
      /* Maybe we already have a push back pointer.  */
      if (fp->_wide_data->_IO_save_base != NULL)
	{
	  free (fp->_wide_data->_IO_save_base);
	  fp->_flags &= ~_IO_IN_BACKUP;
	}
      _IO_wdoallocbuf (fp);
    }

  /* FIXME This can/should be moved to genops ?? */
  if (fp->_flags & (_IO_LINE_BUF | _IO_UNBUFFERED))
    {
      /* We used to flush all line-buffered stream.  This really isn't
	 required by any standard.  My recollection is that
	 traditional Unix systems did this for stdout.  stderr better
	 not be line buffered.  So we do just that here
	 explicitly.  --drepper */
      _IO_acquire_lock (stdout);

      if ((stdout->_flags & (_IO_LINKED | _IO_NO_WRITES | _IO_LINE_BUF))
	  == (_IO_LINKED | _IO_LINE_BUF))
	_IO_OVERFLOW (stdout, EOF);

      _IO_release_lock (stdout);
    }

  _IO_switch_to_get_mode (fp);

  fp->_wide_data->_IO_read_base = fp->_wide_data->_IO_read_ptr =
    fp->_wide_data->_IO_buf_base;
  fp->_wide_data->_IO_read_end = fp->_wide_data->_IO_buf_base;
  fp->_wide_data->_IO_write_base = fp->_wide_data->_IO_write_ptr =
    fp->_wide_data->_IO_write_end = fp->_wide_data->_IO_buf_base;

  const char *read_ptr_copy;
  char accbuf[MB_LEN_MAX];
  size_t naccbuf = 0;
 again:
  count = _IO_SYSREAD (fp, fp->_IO_read_end,
		       fp->_IO_buf_end - fp->_IO_read_end);
  if (count <= 0)
    {
      if (count == 0 && naccbuf == 0)
	{
	  fp->_flags |= _IO_EOF_SEEN;
	  fp->_offset = _IO_pos_BAD;
	}
      else
	fp->_flags |= _IO_ERR_SEEN, count = 0;
    }
  fp->_IO_read_end += count;
  if (count == 0)
    {
      if (naccbuf != 0)
	/* There are some bytes in the external buffer but they don't
	   convert to anything.  */
	__set_errno (EILSEQ);
      return WEOF;
    }
  if (fp->_offset != _IO_pos_BAD)
    _IO_pos_adjust (fp->_offset, count);

  /* Now convert the read input.  */
  fp->_wide_data->_IO_last_state = fp->_wide_data->_IO_state;
  fp->_IO_read_base = fp->_IO_read_ptr;
  const char *from = fp->_IO_read_ptr;
  const char *to = fp->_IO_read_end;
  size_t to_copy = count;
  if (__glibc_unlikely (naccbuf != 0))
    {
      to_copy = MIN (sizeof (accbuf) - naccbuf, count);
      to = __mempcpy (&accbuf[naccbuf], from, to_copy);
      naccbuf += to_copy;
      from = accbuf;
    }
  status = __libio_codecvt_in (cd, &fp->_wide_data->_IO_state,
			       from, to, &read_ptr_copy,
			       fp->_wide_data->_IO_read_end,
			       fp->_wide_data->_IO_buf_end,
			       &fp->_wide_data->_IO_read_end);

  if (__glibc_unlikely (naccbuf != 0))
    fp->_IO_read_ptr += MAX (0, read_ptr_copy - &accbuf[naccbuf - to_copy]);
  else
    fp->_IO_read_ptr = (char *) read_ptr_copy;
  if (fp->_wide_data->_IO_read_end == fp->_wide_data->_IO_buf_base)
    {
      if (status == __codecvt_error)
	{
	out_eilseq:
	  __set_errno (EILSEQ);
	  fp->_flags |= _IO_ERR_SEEN;
	  return WEOF;
	}

      /* The read bytes make no complete character.  Try reading again.  */
      assert (status == __codecvt_partial);

      if (naccbuf == 0)
	{
	  if (fp->_IO_read_base < fp->_IO_read_ptr)
	    {
	      /* Partially used the buffer for some input data that
		 produces no output.  */
	      size_t avail = fp->_IO_read_end - fp->_IO_read_ptr;
	      memmove (fp->_IO_read_base, fp->_IO_read_ptr, avail);
	      fp->_IO_read_ptr = fp->_IO_read_base;
	      fp->_IO_read_end -= avail;
	      goto again;
	    }
	  naccbuf = fp->_IO_read_end - fp->_IO_read_ptr;
	  if (naccbuf >= sizeof (accbuf))
	    goto out_eilseq;

	  memcpy (accbuf, fp->_IO_read_ptr, naccbuf);
	}
      else
	{
	  size_t used = read_ptr_copy - accbuf;
	  if (used > 0)
	    {
	      memmove (accbuf, read_ptr_copy, naccbuf - used);
	      naccbuf -= used;
	    }

	  if (naccbuf == sizeof (accbuf))
	    goto out_eilseq;
	}

      fp->_IO_read_ptr = fp->_IO_read_end = fp->_IO_read_base;

      goto again;
    }

  return *fp->_wide_data->_IO_read_ptr;
}
libc_hidden_def (_IO_wfile_underflow)

enum __codecvt_result
__libio_codecvt_in (struct _IO_codecvt *codecvt, __mbstate_t *statep,
		    const char *from_start, const char *from_end,
		    const char **from_stop,
		    wchar_t *to_start, wchar_t *to_end, wchar_t **to_stop)
{
  enum __codecvt_result result;

  struct __gconv_step *gs = codecvt->__cd_in.step;
  int status;
  size_t dummy;
  const unsigned char *from_start_copy = (unsigned char *) from_start;

  codecvt->__cd_in.step_data.__outbuf = (unsigned char *) to_start;
  codecvt->__cd_in.step_data.__outbufend = (unsigned char *) to_end;
  codecvt->__cd_in.step_data.__statep = statep;

  __gconv_fct fct = gs->__fct;
  if (gs->__shlib_handle != NULL)
    PTR_DEMANGLE (fct);

  status = DL_CALL_FCT (fct,
			(gs, &codecvt->__cd_in.step_data, &from_start_copy,
			 (const unsigned char *) from_end, NULL,
			 &dummy, 0, 0));

  *from_stop = (const char *) from_start_copy;
  *to_stop = (wchar_t *) codecvt->__cd_in.step_data.__outbuf;

  switch (status)
    {
    case __GCONV_OK:
    case __GCONV_EMPTY_INPUT:
      result = __codecvt_ok;
      break;

    case __GCONV_FULL_OUTPUT:
    case __GCONV_INCOMPLETE_INPUT:
      result = __codecvt_partial;
      break;

    default:
      result = __codecvt_error;
      break;
    }

  return result;
}

#ifndef DL_CALL_FCT
# define DL_CALL_FCT(fct, args) fct args
#endif
```
