## Notice

_IO_wfile_jumps can be replace to _IO_wfile_jumps_mmap or _IO_wfile_jumps_maybe_mmap

```C
const struct _IO_jump_t _IO_wfile_jumps libio_vtable =
{
  JUMP_INIT_DUMMY,
  JUMP_INIT(finish, _IO_new_file_finish),
  JUMP_INIT(overflow, (_IO_overflow_t) _IO_wfile_overflow),
  JUMP_INIT(underflow, (_IO_underflow_t) _IO_wfile_underflow),
  JUMP_INIT(uflow, (_IO_underflow_t) _IO_wdefault_uflow),
  JUMP_INIT(pbackfail, (_IO_pbackfail_t) _IO_wdefault_pbackfail),
  JUMP_INIT(xsputn, _IO_wfile_xsputn),
  JUMP_INIT(xsgetn, _IO_file_xsgetn),
  JUMP_INIT(seekoff, _IO_wfile_seekoff),
  JUMP_INIT(seekpos, _IO_default_seekpos),
  JUMP_INIT(setbuf, _IO_new_file_setbuf),
  JUMP_INIT(sync, (_IO_sync_t) _IO_wfile_sync),
  JUMP_INIT(doallocate, _IO_wfile_doallocate),
  JUMP_INIT(read, _IO_file_read),
  JUMP_INIT(write, _IO_new_file_write),
  JUMP_INIT(seek, _IO_file_seek),
  JUMP_INIT(close, _IO_file_close),
  JUMP_INIT(stat, _IO_file_stat),
  JUMP_INIT(showmanyc, _IO_default_showmanyc),
  JUMP_INIT(imbue, _IO_default_imbue)
};
libc_hidden_data_def (_IO_wfile_jumps)


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

const struct _IO_jump_t _IO_wfile_jumps_maybe_mmap libio_vtable =
{
  JUMP_INIT_DUMMY,
  JUMP_INIT(finish, _IO_new_file_finish),
  JUMP_INIT(overflow, (_IO_overflow_t) _IO_wfile_overflow),
  JUMP_INIT(underflow, (_IO_underflow_t) _IO_wfile_underflow_maybe_mmap),
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
  JUMP_INIT(close, _IO_file_close),
  JUMP_INIT(stat, _IO_file_stat),
  JUMP_INIT(showmanyc, _IO_default_showmanyc),
  JUMP_INIT(imbue, _IO_default_imbue)
};
```

```C
off64_t
_IO_wfile_seekoff (FILE *fp, off64_t offset, int dir, int mode)
{
  off64_t result;
  off64_t delta, new_offset;
  long int count;

  /* Short-circuit into a separate function.  We don't want to mix any
     functionality and we don't want to touch anything inside the FILE
     object. */
  if (mode == 0)
    return do_ftell_wide (fp);

  /* POSIX.1 8.2.3.7 says that after a call the fflush() the file
     offset of the underlying file must be exact.  */
  int must_be_exact = ((fp->_wide_data->_IO_read_base
			== fp->_wide_data->_IO_read_end)
		       && (fp->_wide_data->_IO_write_base
			   == fp->_wide_data->_IO_write_ptr));

  bool was_writing = ((fp->_wide_data->_IO_write_ptr
		       > fp->_wide_data->_IO_write_base)
		      || _IO_in_put_mode (fp));

  /* Flush unwritten characters.
     (This may do an unneeded write if we seek within the buffer.
     But to be able to switch to reading, we would need to set
     egptr to pptr.  That can't be done in the current design,
     which assumes file_ptr() is eGptr.  Anyway, since we probably
     end up flushing when we close(), it doesn't make much difference.)
     FIXME: simulate mem-mapped files. */
  if (was_writing && _IO_switch_to_wget_mode (fp))
    return WEOF;

  if (fp->_wide_data->_IO_buf_base == NULL)
    {
      /* It could be that we already have a pushback buffer.  */
      if (fp->_wide_data->_IO_read_base != NULL)
	{
	  free (fp->_wide_data->_IO_read_base);
	  fp->_flags &= ~_IO_IN_BACKUP;
	}
      _IO_doallocbuf (fp);
      _IO_setp (fp, fp->_IO_buf_base, fp->_IO_buf_base);
      _IO_setg (fp, fp->_IO_buf_base, fp->_IO_buf_base, fp->_IO_buf_base);
      _IO_wsetp (fp, fp->_wide_data->_IO_buf_base,
		 fp->_wide_data->_IO_buf_base);
      _IO_wsetg (fp, fp->_wide_data->_IO_buf_base,
		 fp->_wide_data->_IO_buf_base, fp->_wide_data->_IO_buf_base);
    }

  switch (dir)
    {
      struct _IO_codecvt *cv;
      int clen;

    case _IO_seek_cur:
      /* Adjust for read-ahead (bytes is buffer).  To do this we must
	 find out which position in the external buffer corresponds to
	 the current position in the internal buffer.  */
      cv = fp->_codecvt;
      clen = __libio_codecvt_encoding (cv);

      if (mode != 0 || !was_writing)
	{
	  if (clen > 0)
	    {
	      offset -= (fp->_wide_data->_IO_read_end
			 - fp->_wide_data->_IO_read_ptr) * clen;
	      /* Adjust by readahead in external buffer.  */
	      offset -= fp->_IO_read_end - fp->_IO_read_ptr;
	    }
	  else
	    {
	      int nread;

	      delta = (fp->_wide_data->_IO_read_ptr
		       - fp->_wide_data->_IO_read_base);
	      fp->_wide_data->_IO_state = fp->_wide_data->_IO_last_state;
	      nread = __libio_codecvt_length (cv,
					      &fp->_wide_data->_IO_state,
					      fp->_IO_read_base,
					      fp->_IO_read_end, delta);
	      fp->_IO_read_ptr = fp->_IO_read_base + nread;
	      fp->_wide_data->_IO_read_end = fp->_wide_data->_IO_read_ptr;
	      offset -= fp->_IO_read_end - fp->_IO_read_base - nread;
	    }
	}

      if (fp->_offset == _IO_pos_BAD)
	goto dumb;

      /* Make offset absolute, assuming current pointer is file_ptr(). */
      offset += fp->_offset;

      dir = _IO_seek_set;
      break;
    case _IO_seek_set:
      break;
    case _IO_seek_end:
      {
	struct __stat64_t64 st;
	if (_IO_SYSSTAT (fp, &st) == 0 && S_ISREG (st.st_mode))
	  {
	    offset += st.st_size;
	    dir = _IO_seek_set;
	  }
	else
	  goto dumb;
      }
    }

  _IO_free_wbackup_area (fp);

  /* At this point, dir==_IO_seek_set. */

  /* If destination is within current buffer, optimize: */
  if (fp->_offset != _IO_pos_BAD && fp->_IO_read_base != NULL
      && !_IO_in_backup (fp))
    {
      off64_t start_offset = (fp->_offset
                              - (fp->_IO_read_end - fp->_IO_buf_base));
      if (offset >= start_offset && offset < fp->_offset)
	{
	  _IO_setg (fp, fp->_IO_buf_base,
		    fp->_IO_buf_base + (offset - start_offset),
		    fp->_IO_read_end);
	  _IO_setp (fp, fp->_IO_buf_base, fp->_IO_buf_base);
	  _IO_wsetg (fp, fp->_wide_data->_IO_buf_base,
		     fp->_wide_data->_IO_buf_base,
		     fp->_wide_data->_IO_buf_base);
	  _IO_wsetp (fp, fp->_wide_data->_IO_buf_base,
		     fp->_wide_data->_IO_buf_base);

	  if (adjust_wide_data (fp, false))
	    goto dumb;

	  _IO_mask_flags (fp, 0, _IO_EOF_SEEN);
	  goto resync;
	}
    }

  if (fp->_flags & _IO_NO_READS)
    goto dumb;

  /* Try to seek to a block boundary, to improve kernel page management. */
  new_offset = offset & ~(fp->_IO_buf_end - fp->_IO_buf_base - 1);
  delta = offset - new_offset;
  if (delta > fp->_IO_buf_end - fp->_IO_buf_base)
    {
      new_offset = offset;
      delta = 0;
    }
  result = _IO_SYSSEEK (fp, new_offset, 0);
  if (result < 0)
    return EOF;
  if (delta == 0)
    count = 0;
  else
    {
      count = _IO_SYSREAD (fp, fp->_IO_buf_base,
			   (must_be_exact
			    ? delta : fp->_IO_buf_end - fp->_IO_buf_base));
      if (count < delta)
	{
	  /* We weren't allowed to read, but try to seek the remainder. */
	  offset = count == EOF ? delta : delta-count;
	  dir = _IO_seek_cur;
	  goto dumb;
	}
    }
  _IO_setg (fp, fp->_IO_buf_base, fp->_IO_buf_base + delta,
	    fp->_IO_buf_base + count);
  _IO_setp (fp, fp->_IO_buf_base, fp->_IO_buf_base);
  _IO_wsetg (fp, fp->_wide_data->_IO_buf_base,
	     fp->_wide_data->_IO_buf_base, fp->_wide_data->_IO_buf_base);
  _IO_wsetp (fp, fp->_wide_data->_IO_buf_base, fp->_wide_data->_IO_buf_base);

  if (adjust_wide_data (fp, true))
    goto dumb;

  fp->_offset = result + count;
  _IO_mask_flags (fp, 0, _IO_EOF_SEEN);
  return offset;
 dumb:

  _IO_unsave_markers (fp);
  result = _IO_SYSSEEK (fp, offset, dir);
  if (result != EOF)
    {
      _IO_mask_flags (fp, 0, _IO_EOF_SEEN);
      fp->_offset = result;
      _IO_setg (fp, fp->_IO_buf_base, fp->_IO_buf_base, fp->_IO_buf_base);
      _IO_setp (fp, fp->_IO_buf_base, fp->_IO_buf_base);
      _IO_wsetg (fp, fp->_wide_data->_IO_buf_base,
		 fp->_wide_data->_IO_buf_base, fp->_wide_data->_IO_buf_base);
      _IO_wsetp (fp, fp->_wide_data->_IO_buf_base,
		 fp->_wide_data->_IO_buf_base);
    }
  return result;

resync:
  /* We need to do it since it is possible that the file offset in
     the kernel may be changed behind our back. It may happen when
     we fopen a file and then do a fork. One process may access the
     file and the kernel file offset will be changed. */
  if (fp->_offset >= 0)
    _IO_SYSSEEK (fp, fp->_offset, 0);

  return offset;
}
libc_hidden_def (_IO_wfile_seekoff)

int
_IO_switch_to_wget_mode (FILE *fp)
{
  if (fp->_wide_data->_IO_write_ptr > fp->_wide_data->_IO_write_base)
    if ((wint_t)_IO_WOVERFLOW (fp, WEOF) == WEOF)
      return EOF;
  if (_IO_in_backup (fp))
    fp->_wide_data->_IO_read_base = fp->_wide_data->_IO_backup_base;
  else
    {
      fp->_wide_data->_IO_read_base = fp->_wide_data->_IO_buf_base;
      if (fp->_wide_data->_IO_write_ptr > fp->_wide_data->_IO_read_end)
	fp->_wide_data->_IO_read_end = fp->_wide_data->_IO_write_ptr;
    }
  fp->_wide_data->_IO_read_ptr = fp->_wide_data->_IO_write_ptr;

  fp->_wide_data->_IO_write_base = fp->_wide_data->_IO_write_ptr
    = fp->_wide_data->_IO_write_end = fp->_wide_data->_IO_read_ptr;

  fp->_flags &= ~_IO_CURRENTLY_PUTTING;
  return 0;
}
libc_hidden_def (_IO_switch_to_wget_mode)

#define _IO_WOVERFLOW(FP, CH) WJUMP1 (__overflow, FP, CH)
#define WJUMP1(FUNC, THIS, X1) (_IO_WIDE_JUMPS_FUNC(THIS)->FUNC) (THIS, X1)
```
