## Notice

```C
const struct _IO_jump_t _IO_wfile_jumps_mmap libio_vtable =
{
  JUMP_INIT_DUMMY,
  JUMP_INIT(finish, _IO_new_file_finish),
  JUMP_INIT(overflow, (_IO_overflow_t) _IO_wfile_overflow),
  JUMP_INIT(underflow, (_IO_underflow_t) _IO_wfile_underflow_mmap),
  JUMP_INIT(uflow, (_IO_underflow_t) _IO_wdefault_uflow),
  JUMP_INIT(pbackfail, (_IO_pbackfail_t) _IO_wdefault_pbackfail),
  JUMP_INIT(xsputn, _IO_wfile_xsputn),
  JUMP_INIT(xsgetn, _IO_file_xsgetn),
  JUMP_INIT(seekoff, _IO_wfile_seekoff),
  JUMP_INIT(seekpos, _IO_default_seekpos),
  JUMP_INIT(setbuf, _IO_file_setbuf_mmap),
  JUMP_INIT(sync, (_IO_sync_t) _IO_wfile_sync),
  JUMP_INIT(doallocate, _IO_wfile_doallocate),
  JUMP_INIT(read, _IO_file_read),
  JUMP_INIT(write, _IO_new_file_write),
  JUMP_INIT(seek, _IO_file_seek),
  JUMP_INIT(close, _IO_file_close_mmap),
  JUMP_INIT(stat, _IO_file_stat),
  JUMP_INIT(showmanyc, _IO_default_showmanyc),
  JUMP_INIT(imbue, _IO_default_imbue)
};

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

/* Extra data for wide character streams.  */
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
static wint_t
_IO_wfile_underflow_mmap (FILE *fp)
{
  struct _IO_codecvt *cd;
  const char *read_stop;

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
  if (fp->_IO_read_ptr >= fp->_IO_read_end
      /* No.  But maybe the read buffer is not fully set up.  */
      && _IO_file_underflow_mmap (fp) == EOF)
    /* Nothing available.  _IO_file_underflow_mmap has set the EOF or error
       flags as appropriate.  */
    return WEOF;

  /* There is more in the external.  Convert it.  */
  read_stop = (const char *) fp->_IO_read_ptr;

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

  fp->_wide_data->_IO_last_state = fp->_wide_data->_IO_state;
  fp->_wide_data->_IO_read_base = fp->_wide_data->_IO_read_ptr =
    fp->_wide_data->_IO_buf_base;
  __libio_codecvt_in (cd, &fp->_wide_data->_IO_state,
		      fp->_IO_read_ptr, fp->_IO_read_end,
		      &read_stop,
		      fp->_wide_data->_IO_read_ptr,
		      fp->_wide_data->_IO_buf_end,
		      &fp->_wide_data->_IO_read_end);

  fp->_IO_read_ptr = (char *) read_stop;

  /* If we managed to generate some text return the next character.  */
  if (fp->_wide_data->_IO_read_ptr < fp->_wide_data->_IO_read_end)
    return *fp->_wide_data->_IO_read_ptr;

  /* There is some garbage at the end of the file.  */
  __set_errno (EILSEQ);
  fp->_flags |= _IO_ERR_SEEN;
  return WEOF;
}

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
#ifdef PTR_DEMANGLE
  if (gs->__shlib_handle != NULL)
    PTR_DEMANGLE (fct);
#endif

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
