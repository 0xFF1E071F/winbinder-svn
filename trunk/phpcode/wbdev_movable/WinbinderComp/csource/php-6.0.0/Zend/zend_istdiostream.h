/* 
   +----------------------------------------------------------------------+
   | Zend Engine                                                          |
   +----------------------------------------------------------------------+
   | Copyright (c) 1998-2006 Zend Technologies Ltd. (http://www.zend.com) |
   +----------------------------------------------------------------------+
   | This source file is subject to version 2.00 of the Zend license,     |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.zend.com/license/2_00.txt.                                |
   | If you did not receive a copy of the Zend license and are unable to  |
   | obtain it through the world-wide-web, please send a note to          |
   | license@zend.com so we can mail you a copy immediately.              |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   +----------------------------------------------------------------------+
*/

/* $Id: zend_istdiostream.h,v 1.7 2006/01/04 23:52:06 andi Exp $ */

#ifndef _ZEND_STDIOSTREAM
#define _ZEND_STDIOSTREAM

#if defined(ZTS) && !defined(HAVE_CLASS_ISTDIOSTREAM)
class istdiostream : public istream
{
private:
	stdiobuf _file;
public:
	istdiostream (FILE* __f) : istream(), _file(__f) { init(&_file); }
	stdiobuf* rdbuf()/* const */ { return &_file; }
};
#endif

#endif

/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * indent-tabs-mode: t
 * End:
 */
